#include <Arduino.h>
// Entradas (nomes e GPIOs)
#define ENTRADA_VP   36    //ED0 -    SENSOR DE BARREIRA
#define ENTRADA_VN   39    //ED1 -    SENSOR MAGAZINE RECUADO
#define ENTRADA_D34  34    //ED2 -    SENSOR MAGAZINE AVANÇADO
#define ENTRADA_D32  32    //ED3 -    SENSOR ROTATOR AVANÇADO
#define ENTRADA_D33  33    //ED4 -    PRESSOSTATO
#define ENTRADA_D25  25    //ED5 -    SENSOR ROTATIVO RECUADO
#define ENTRADA_D26  26    //ED6 -    
#define ENTRADA_D27  27    //ED7 -

// Saídas correspondentes
#define SAIDA_D23  23    //SD0 -     AVANÇO DO ATUADOR ROTATIVO
#define SAIDA_D22  22    //SD1 -     RECUADO
#define SAIDA_D21  21    //SD2 -     ATUADOR MAGAZINE
#define SAIDA_D19  19    //SD3 -     VÁCUO
#define SAIDA_D18  18    //SD4 -     SOLTA PEÇA (CONTROLE DO VÁCUO)
#define SAIDA_TX2  17    //SD5 - 
#define SAIDA_RX2  16    //SD6 - 
#define SAIDA_D4   4     //SD7 - 

  // Definição dos estados
enum Estado {
    ESTADO_1,
    ESTADO_2,
    ESTADO_3,
    ESTADO_4,
    ESTADO_5,
    ESTADO_6,
    ESTADO_7,
    ESTADO_8,
    ESTADO_9,
    ESTADO_10,

};

Estado estadoAtual = ESTADO_1;

void setup() { 
  // Configurar entradas
  pinMode(ENTRADA_VP, INPUT);
  pinMode(ENTRADA_VN, INPUT);
  pinMode(ENTRADA_D34, INPUT);
  pinMode(ENTRADA_D32, INPUT);
  pinMode(ENTRADA_D33, INPUT);
  pinMode(ENTRADA_D25, INPUT);
  pinMode(ENTRADA_D26, INPUT);
  pinMode(ENTRADA_D27, INPUT);

  // Configurar saídas
  pinMode(SAIDA_D23, OUTPUT);
  pinMode(SAIDA_D22, OUTPUT);
  pinMode(SAIDA_D21, OUTPUT);
  pinMode(SAIDA_D19, OUTPUT);
  pinMode(SAIDA_D18, OUTPUT);
  pinMode(SAIDA_TX2, OUTPUT);
  pinMode(SAIDA_RX2, OUTPUT);
  pinMode(SAIDA_D4, OUTPUT);

   // Pull-Down das entradas digitais
  digitalWrite(ENTRADA_VP, LOW);
  digitalWrite(ENTRADA_VN, LOW);
  digitalWrite(ENTRADA_D34, LOW);
  digitalWrite(ENTRADA_D33, LOW);
  digitalWrite(ENTRADA_D32, LOW);
  digitalWrite(ENTRADA_D27, LOW);
  digitalWrite(ENTRADA_D26, LOW);
  digitalWrite(ENTRADA_D25, LOW);

  // Reset das Saídas
  digitalWrite(SAIDA_TX2, LOW);
  digitalWrite(SAIDA_RX2, LOW);
  digitalWrite(SAIDA_D4, LOW);
  digitalWrite(SAIDA_D23, LOW);
  digitalWrite(SAIDA_D22, LOW);
  digitalWrite(SAIDA_D21, LOW);
  digitalWrite(SAIDA_D19, LOW);
  digitalWrite(SAIDA_D18, LOW);
}


void loop() {
    switch (estadoAtual) {
        case ESTADO_1:  
            if (digitalRead(ENTRADA_VP) == LOW) {   // SENSOR DE BARREIRA ativado
                digitalWrite(SAIDA_D21, HIGH);       // ATUADOR MAGAZINE liga
               
                estadoAtual = ESTADO_2; 
            }     
                                                                    
            break;

        case ESTADO_2:
            if (digitalRead(ENTRADA_D34) == HIGH) { // SENSOR MAGAZINE AVANÇADO ativado
                digitalWrite(SAIDA_D21, LOW); // ATUADOR MAGAZINE desliga
                digitalWrite(SAIDA_D23, HIGH); // ATUADOR AVANÇADO liga
                digitalWrite(SAIDA_D19, HIGH); // VÁCUO liga
                delay(1000);
                estadoAtual = ESTADO_3;
            }

            break;

        case ESTADO_3:
            if (digitalRead(ENTRADA_D32) == HIGH){ // SENSOR RETATOR AVANÇADO ativado
                digitalWrite(SAIDA_D23, LOW); // ATUADOR AVANÇADO desliga 
                digitalWrite(SAIDA_D22, HIGH);  // ATUADOR RECUADO liga
                delay(2000);                           
                estadoAtual = ESTADO_4;
            }
        
            break;

        case ESTADO_4:              

            if (digitalRead(ENTRADA_D25) == HIGH){ // SENSOR RECUADO ativado
              digitalWrite(SAIDA_D19, LOW); // VÁCUO desliga
              digitalWrite(SAIDA_D18, HIGH); // SOLTA A PEÇA liga
              delay(1000);
              estadoAtual = ESTADO_5;
            }
                
            break;

        case ESTADO_5:

        if (digitalRead(ENTRADA_D25) == HIGH){
            digitalWrite(SAIDA_D22, LOW); // ATUADOR RECUADO DESLIGA
            digitalWrite(SAIDA_D23, HIGH); // AVANÇO LIGA
            delay(1300); 
            digitalWrite(SAIDA_D23, LOW); // AVANÇO PARA
            digitalWrite(SAIDA_D18, LOW);  // SOLTA PEÇA desliga
            estadoAtual = ESTADO_1;
        }
           
            break;
    }
}