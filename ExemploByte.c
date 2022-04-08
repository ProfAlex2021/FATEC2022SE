int leds[8] = {2,3,4,5,6,7,8,9};
int ligados[8] = {0,0,0,0,0,0,0,0};

void apagar_todos(){
    for(int i = 0; i < 8; i++) 
        digitalWrite(leds[i], LOW);
}

void acender(){
    for(int i = 0; i < 8; i++)
        digitalWrite(leds[i], ligados[i]);
}

void valor2led(int valor){
    int quociente = valor;
    for(int i = 0; i < 8; i++){
        ligados[i] = quociente % 2;
        quociente /= 2;
    }
    acender();
}

void setup(){
    delay(1000);
    valor2led(85);
    delay(2000);
    apagar_todos();
    delay(1000);
    valor2led(170);
    delay(2000);
    apagar_todos();
    delay(1000);
}

void loop(){
    for(int i = 1; i < 256; i *= 2){
        valor2led(i);
        delay(500);
    }
    for(int i = 64; i > 1; i /= 2){
        valor2led(i);
        delay(500);
    }
}