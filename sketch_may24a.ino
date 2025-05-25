#define RELE 3
#define SENSOR_SOLO 2
#define LDR A0         // Pino analógico para o LDR

bool irrigar = false;
int luminosidade = 0;
int limiteLuz = 500;   // Ajuste conforme necessário (valores mais altos = menos luz)

void setup() {
    pinMode(RELE, OUTPUT);
    pinMode(SENSOR_SOLO, INPUT);
    digitalWrite(RELE, HIGH);  // Começa com o relé desligado
    Serial.begin(9600);        // Para debug (opcional)
}

void loop() {
    // Lê o sensor de umidade do solo
    irrigar = digitalRead(SENSOR_SOLO);

    // Lê o sensor de luminosidade (0 = escuro, 1023 = muito claro)
    luminosidade = analogRead(LDR);

    // Se estiver claro o suficiente (dia) e o solo precisar de água
    if (irrigar && (luminosidade > limiteLuz)) {
        digitalWrite(RELE, LOW);  // Liga a irrigação
        Serial.println("Irrigando! (Dia e solo seco)");
    } else {
        digitalWrite(RELE, HIGH); // Desliga a irrigação
        Serial.println("Irrigação pausada (noite ou solo úmido)");
    }

    // Debug no Monitor Serial (opcional, mas tá dando erro, rever depois)
    Serial.print("Luminosidade: ");
    Serial.println(luminosidade);

    delay(1000);  // Verifica a cada 1 segundo (cada segundo é 1000 milisegundos)
}