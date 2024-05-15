module MIPS(
    //INPUT
    clk,
    rst_n,
    in_valid,
    instruction,

    //OUTPUT
    out_valid,
    instruction_fail,
    out_0,
    out_1,
    out_2,
    out_3,
    out_4,
    out_5
);
// INPUT
input clk;
input rst_n;
input in_valid;
input [31:0] instruction;

// OUTPUT
output logic out_valid, instruction_fail;
output logic [15:0] out_0, out_1, out_2, out_3, out_4, out_5;

//================================================================
// DESIGN 
//================================================================

logic in_valid_1, in_valid_2, in_valid_3;
logic [31:0] instruction_reg;

//layer1 -> get instruction
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        in_valid_1 <= 0;
    end
    else begin
        if (in_valid) begin
            instruction_reg <= instruction;
        end
        in_valid_1 <= in_valid;
    end
end

//layer2
logic [1:0] opcode_comb, opcode_reg;
logic [2:0] func_comb, func_reg;

logic [15:0] value_rs_comb, value_rs_reg;
logic [15:0] value_rt_comb, value_rt_reg;

logic [4:0] dest_comb, dest_reg;
logic [4:0] dest_reg_1;

logic [15:0] immediate_comb;
logic [5:0] shamt_comb, shamt_reg;

logic [15:0] result_comb, result_reg;
logic [15:0] add_reg;

assign shamt_comb = instruction_reg[10:6];
assign immediate_comb = instruction_reg[15:0];

always_comb begin
    if (instruction_reg[31:26] == 6'd0) begin
        case (instruction_reg[5:0])
            6'b100100: func_comb = 1;
            6'b100101: func_comb = 2;
            6'b100111: func_comb = 3;
            6'b000000: func_comb = 4;
            6'b000010: func_comb = 5;
            default: func_comb = 0;
        endcase
    end
    else begin
        func_comb = 0;
    end
end
always_comb begin
    case (instruction_reg[31:26])
        6'b000000: opcode_comb = 0;
        default: opcode_comb = 1;
    endcase
end
always_comb begin
    if (dest_reg_1 == instruction_reg[25:21]) value_rs_comb = result_reg;
    else begin
        case (instruction_reg[25:21])
            5'b10001: value_rs_comb = out_0;
            5'b10010: value_rs_comb = out_1;
            5'b01000: value_rs_comb = out_2;
            5'b10111: value_rs_comb = out_3;
            5'b11111: value_rs_comb = out_4;
            5'b10000: value_rs_comb = out_5;
            default: value_rs_comb = 16'd0;
        endcase
    end
end

always_comb begin
    if (dest_reg_1 == instruction_reg[20:16]) value_rt_comb = result_reg;
    else begin
        case (instruction_reg[20:16])
            5'b10001: value_rt_comb = out_0;
            5'b10010: value_rt_comb = out_1;
            5'b01000: value_rt_comb = out_2;
            5'b10111: value_rt_comb = out_3;
            5'b11111: value_rt_comb = out_4;
            5'b10000: value_rt_comb = out_5;
            default: value_rt_comb = 16'd0;
        endcase
    end
end

always_comb begin
    case (instruction_reg[31:26])
        6'b000000: begin
            dest_comb = instruction_reg[15:11];
        end
        6'b001000: begin
            dest_comb = instruction_reg[20:16];
        end
        default: begin
            dest_comb = 0;
        end
    endcase
end

always_ff @ (posedge clk, negedge rst_n) begin
    if (~rst_n) begin
        in_valid_2 <= 0;
    end
    else begin
        if (in_valid_1) begin
            value_rs_reg <= value_rs_comb;
            value_rt_reg <= value_rt_comb;
            dest_reg <= dest_comb;
            add_reg <= (opcode_comb == 0) ? value_rt_comb : immediate_comb;
//          immediate_reg <= immediate_comb;
            func_reg <= func_comb;
            opcode_reg <= opcode_comb;
            shamt_reg <= shamt_comb;
        end
        in_valid_2 <= in_valid_1;
    end
end

//layer3

always_comb begin
    case (func_reg)
        6'd0: result_comb = value_rs_reg + add_reg;
        6'd1: result_comb = value_rs_reg & value_rt_reg;
        6'd2: result_comb = value_rs_reg | value_rt_reg;
        6'd3: result_comb = ~(value_rs_reg | value_rt_reg);
        6'd4: result_comb = value_rt_reg << shamt_reg;
        6'd5: result_comb = value_rt_reg >> shamt_reg;
        default: result_comb = 16'd0;
    endcase
end

always_ff @ (negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        in_valid_3 <= 0;
        result_reg <= 0;
    end
    else begin
        if (in_valid_2) begin
            result_reg <= result_comb;
            dest_reg_1 <= dest_reg;
        end
        in_valid_3 <= in_valid_2;
    end
end

//layer4

always_ff @ (negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        out_valid <= 0;
        instruction_fail <= 0;
        out_0 <= 0;
        out_1 <= 0;
        out_2 <= 0;
        out_3 <= 0;
        out_4 <= 0;
        out_5 <= 0;
    end
    else if (in_valid_3) begin
        out_valid <= 1;
        case (dest_reg_1)
            5'b10001: begin
                out_0 <= result_reg;
                instruction_fail <= 0;
            end
            5'b10010: begin
                out_1 <= result_reg;
                instruction_fail <= 0;
            end
            5'b01000: begin
                out_2 <= result_reg;
                instruction_fail <= 0;
            end
            5'b10111: begin
                out_3 <= result_reg;
                instruction_fail <= 0;
            end
            5'b11111: begin
                out_4 <= result_reg;
                instruction_fail <= 0;
            end
            5'b10000: begin
                out_5 <= result_reg;
                instruction_fail <= 0;
            end
            default: instruction_fail <= 1;
        endcase
    end
    else begin
        out_0 <= 0;
        out_1 <= 0;
        out_2 <= 0;
        out_3 <= 0;
        out_4 <= 0;
        out_5 <= 0;
        out_valid <= in_valid_3;
    end
end

endmodule
