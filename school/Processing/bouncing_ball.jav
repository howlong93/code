float x = 400;
float y = 400;
float r = 20;
float vx, vy;
float gravity = 1;
int cnt = 0, cntms = 0;

void setup() {
  size(800, 800);
  vx = 20;
  vy = -10;
}

void draw() {
  background(256);
  fill (255, 155, 0);
  circle (x, y, 2*r);
  x += vx;
  y += vy;
  vy += gravity;
  
  if (cnt > 0) cnt++;
  if (cnt >= 1000000) cnt = 0;
  
  if (cntms > 0) cntms++;
  if (cntms >= 10) cntms = 0;
  
  rect (mouseX-100, 700, 200, 20);
  if (x+r >= width || x-r <= 1) {
    vx *= -1;    
  }
  
  if (y+r >= height || (y-r) <= 0.5 && cnt == 0) {
    vy *= -0.97;
    cnt++;
  }
 
  if (x >= mouseX-100 && x <= mouseX+100 && y+r >= 700 && cntms == 0) {
    vy *= -1;
    cntms++;
  }
 
}
