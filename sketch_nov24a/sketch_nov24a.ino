const int data_pin = 4; // DS (Chân 14)
const int stcp_pin = 5; // ST_CP / Latch (Chân 12)
const int shcp_pin = 6; // SH_CP / Clock (Chân 11)

uint16_t data16 = 0b1010101010101010;

void setup() {
  pinMode(data_pin, OUTPUT);
  pinMode(stcp_pin, OUTPUT);
  pinMode(shcp_pin, OUTPUT);
}

void loop() {
  // Đẩy đủ 16 bit trước khi chốt
  digitalWrite(stcp_pin, LOW);
  shiftOut(data_pin, shcp_pin, MSBFIRST, data16 >> 8);   // Gửi 8 bit cao (sang IC thứ 2)
  shiftOut(data_pin, shcp_pin, MSBFIRST, data16 & 0xFF); // Gửi 8 bit thấp (ở lại IC thứ 1)
  digitalWrite(stcp_pin, HIGH);

  delay(1000);

  // Đảo bit (~data16) để tạo hiệu ứng nhấp nháy xen kẽ
  data16 = ~data16;
}
