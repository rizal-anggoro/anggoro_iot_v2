#include "Parser.h"

extern MatrixPixel matrixPixel;
extern DeskPixel deskPixel;

void Parser::let(String receive_data) {
  Serial.println(receive_data);
  
  int a = receive_data.indexOf(";");
  int b = receive_data.lastIndexOf(";");
  String data_path = receive_data.substring(0, a);
  String data = receive_data.substring((a + 1), b);

  if (data_path.indexOf("/matrix/brightness") != -1) {
    matrixPixel.setBrightness(data.toInt());
  } else if (data_path.indexOf("/desk/brightness") != -1) {
    deskPixel.setBrightness(data.toInt());
  }
}
