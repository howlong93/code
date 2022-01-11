void setup () {
  size(800, 800);
  frameRate(24);
  noStroke();
}

void draw() {
  background(0);
  
  for (int i = 1; i < 6; i++) {
    push();
    translate(400, 400);
    rotate (radians(frameCount * i));
    for (int j = 0; j < 6; j++) {
      fill (200, 200, 30 * i);
      rect (0, -5, 50 * i + 50, 5);
      rotate(radians(60));
    }
    pop();
  }
}
  
