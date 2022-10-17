#include <Wire.h> //Biblioteca utilizada gerenciar a comunicação entre dispositicos através do protocolo I2C
#include <LiquidCrystal_I2C.h> //Biblioteca utilizada para controlar o display 16x2 através do I2C

#define col  16 //Define o número de colunas do display utilizado
#define lin   2 //Define o número de linhas do display utilizado
#define ende  0x27 //Define o endereço do display

int pinoanalogico = A0; //Pino analógico do sensor de umidade deve ser ligado a porta analógica A0 do arduino
int valorlido; // Váriavel criada para receber o valor aferido pelo sensor de umidade

LiquidCrystal_I2C lcd(ende, col, lin); //Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas

void setup() {
  Serial.begin (9600);
  pinMode (pinoanalogico, INPUT);
  lcd.init(); //Inicializa a comunicação com o display já conectado
  lcd.clear(); //Limpa a tela do display
  lcd.backlight(); //Aciona a luz de fundo do display

  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("MONITOR DE "); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("UMIDADE DO SOLO"); //Exibe o texto no visor LCD
  delay (2000);
  lcd.clear();  //Apaga o texto do visor LCD
  lcd.setCursor(5, 0); //Inicia a exibição do texto na linha 5 da primeira coluna do display
  lcd.print("ROBOTICA"); 
  lcd.setCursor(5, 1); //Inicia a exibição do texto na linha 5 da segunda coluna do display
  lcd.print("ARDUINO");
  delay(500);  //Comando utilizado para estabelecer um intervalo (em milisegundos) antes de executar a próxima linha do código.
  lcd.noDisplay();// Desliga Display:
  delay(500);
  lcd.display();// Liga Display:
  delay(500);
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
  
 }

void loop() {
  valorlido = analogRead(pinoanalogico);
  Serial.println (valorlido);//mostra no monitor serial o valor que esta sendo lido
  delay (100);
  if (valorlido > 800) { //Condicional que determina a ação que deve ocorrer a partir do valor definido
    lcd.clear ();
    lcd.print ("REGUE A PLANTA !");
    lcd.setCursor (3, 1); //comando para escrever na linha de baixo
    lcd.print ("SOLO SECO ");
    delay (100);
  } else {
    lcd.clear ();
    lcd.setCursor (3, 0); //comando para escrever na linha de baixo
    lcd.print ("TUDO OK !");
    lcd.setCursor (3, 1); //comando para escrever na linha de baixo
    lcd.print ("SOLO UMIDO ");
    delay (100);
  }
}
