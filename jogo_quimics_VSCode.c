#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 OLED(128, 64, &Wire, -1);

const char* Elements [] = {
  "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", 
"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn","Fe", "Co", "Ni", "Cu", "Zn",
 "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag",
  "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", 
  "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg","Tl",
   "Pb", "Bi", "Po", "At", "Rn","Fr","Ra"};

const char* ElementClass[] = { 
  "A", "A", "M", "M", "A", "A", "A", "A", "A", "A",  // H - Ne
  "M", "M", "M", "M", "A", "A", "A", "A", "M", "M",  // Na - Ca
  "M", "M", "M", "M", "M", "M", "M", "M", "M", "M",  // Sc - Zn
  "M", "A", "A", "A", "A", "A", "M", "M", "M", "M",  // Ga - Zr
  "M", "M", "M", "M", "M", "M", "M", "M", "M", "M",  // Nb - Sn
  "M", "A", "A", "A", "M", "M", "M", "M", "M", "M",  // Sb - Lu
  "M", "M", "M", "M", "M", "M", "M", "M", "M", "M",  // Hf - Hg
  "M", "M", "M", "A", "A", "A", "M", "M"            // Tl - Ra
};

int RespostaCerta = 1;
int RespostaErrada = 1;
int RandomElement = 0;
int RandomElement2 = 0;
int Pontos = 0;

void setup() {
  //Prepara o jogo todo e faz o que precisa para a primeira pergunta
  Serial.begin(9600);
delay(200);

  if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed!");
    while (1);
 
  }
 pinMode(A0,INPUT_PULLUP) ; 
  pinMode(A1,INPUT_PULLUP) ; 
 RandomElement = random (0,88);
 RandomElement2 = random (0,88);

 OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setTextSize(12);
  OLED.setCursor(5, 5);
  OLED.println("Jogo de Quimica");
  OLED.display();
  delay(1500);

}

void perguntar(){

// Escolher dois elementos aleatórios
 RandomElement = random (0,88);
 RandomElement2 = random (0,88); 

 OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setTextSize(1);
  OLED.setCursor(5, 5);
  OLED.print("Elemento 1 - ");
  OLED.print(Elements[RandomElement]);
  
  OLED.print("    Elemento 2 - ");
  OLED.println(Elements[RandomElement2]);

  OLED.setTextSize(1);
  OLED.setCursor(5, 15);
  OLED.print("Resposta...");
  delay(1250);
  OLED.print(ElementClass[RandomElement]);
  OLED.println(ElementClass[RandomElement2]);

  OLED.invertDisplay(1);
  OLED.display();


}

void loop() {

RespostaCerta = digitalRead(A0);
RespostaErrada = digitalRead(A1);

if (RespostaCerta  == LOW){

Pontos = Pontos + 5;

OLED.clearDisplay();
delay(1000);
OLED.setTextSize(1);
  OLED.setCursor(5, 15);
  OLED.print("Pontos: ");
  delay(1250);
  OLED.print(Pontos);

  OLED.invertDisplay(1);
  OLED.display();

delay(1000);

perguntar();

delay(1000);

}

if (RespostaErrada == LOW){

delay(1000);


Pontos = Pontos - 5;

OLED.clearDisplay();
delay(1000);
OLED.setTextSize(1);
  OLED.setCursor(5, 15);
  OLED.print("Pontos: ");
  delay(1250);
  OLED.print(Pontos);

  OLED.invertDisplay(1);
  OLED.display();

delay(1000);

perguntar();


}

}