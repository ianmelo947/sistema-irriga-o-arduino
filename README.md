Sistema de Irrigação Automática com Arduino
Um projeto simples, eficiente e de baixo custo para automação residencial ou agrícola de irrigação, utilizando um Arduino, um sensor de umidade do solo e um sensor de luminosidade (LDR).
📋 Sobre o Projeto
Este projeto tem como objetivo automatizar o processo de rega de plantas. O sistema monitora dois fatores principais antes de acionar a bomba d'água (via módulo relé):
Umidade do Solo: Verifica se a terra está seca.
Luminosidade (LDR): Garante que a irrigação aconteça apenas em horários de claridade (dia), evitando regas noturnas desnecessárias que podem favorecer o surgimento de fungos nas plantas.
🛠️ Componentes Utilizados
1x Placa Arduino (Uno, Nano, Mega, etc.)
1x Módulo Relé de 1 canal
1x Sensor de Umidade do Solo (Digital/Analógico adaptado)
1x Sensor LDR (Fotoresistor)
1x Resistor (adequado para o divisor de tensão do LDR)
Fios Jumper e protoboard
Bomba d'água / Eletroválvula (compatível com a especificação do relé)
🔌 Esquema de Conexão (Pinagem)
Componente
Pino no Arduino
Descrição
Módulo Relé
Pino 3
Aciona o circuito de potência da bomba
Sensor de Solo
Pino 2
Lê o estado de umidade (Digital)
Sensor LDR
Pino A0
Lê o nível de luminosidade do ambiente (Analógico)

⚙️ Como o Código Funciona
O código realiza leituras contínuas a cada 1 segundo (1000 ms) e aplica uma lógica condicional:
Leitura da Umidade: O pino digital 2 lê se o solo está seco.
Leitura da Luz: O pino analógico A0 mede a claridade (de 0 a 1023). O limiar (limiteLuz) padrão está configurado em 500. Valores maiores indicam mais claridade.
Ação:
Se o solo estiver precisando de água E estiver claro o suficiente (luminosidade > limiteLuz), o relé é ativado (LOW, dependendo do módulo) e a irrigação começa.
Caso contrário, o relé permanece desativado (HIGH).
💻 Código Fonte
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

    // Debug no Monitor Serial
    Serial.print("Luminosidade: ");
    Serial.println(luminosidade);

    delay(1000);  // Verifica a cada 1 segundo
}


🚀 Como Executar
Conecte os componentes ao seu Arduino conforme a tabela de pinagem.
Abra a IDE do Arduino.
Copie o código acima e cole em um novo esboço (sketch).
Selecione a placa e a porta COM corretas no menu Ferramentas.
Faça o upload (carregamento) do código para o Arduino.
Abra o Monitor Serial (9600 baud) para acompanhar os valores de luminosidade e o status da irrigação.
💡 Próximos Passos e Melhorias
Calibrar o limiteLuz de acordo com o ambiente onde o sensor LDR será instalado.
Substituir o delay(1000) por millis() caso queira expandir o projeto para executar outras tarefas simultaneamente sem travar o loop.
Sistema de Irrigação Automática com Arduino
Um projeto simples, eficiente e de baixo custo para automação residencial ou agrícola de irrigação, utilizando um Arduino, um sensor de umidade do solo e um sensor de luminosidade (LDR).
📋 Sobre o Projeto
Este projeto tem como objetivo automatizar o processo de rega de plantas. O sistema monitora dois fatores principais antes de acionar a bomba d'água (via módulo relé):
Umidade do Solo: Verifica se a terra está seca.
Luminosidade (LDR): Garante que a irrigação aconteça apenas em horários de claridade (dia), evitando regas noturnas desnecessárias que podem favorecer o surgimento de fungos nas plantas.
🛠️ Componentes Utilizados
1x Placa Arduino (Uno, Nano, Mega, etc.)
1x Módulo Relé de 1 canal
1x Sensor de Umidade do Solo (Digital/Analógico adaptado)
1x Sensor LDR (Fotoresistor)
1x Resistor (adequado para o divisor de tensão do LDR)
Fios Jumper e protoboard
Bomba d'água / Eletroválvula (compatível com a especificação do relé)
🔌 Esquema de Conexão (Pinagem)
Componente
Pino no Arduino
Descrição
Módulo Relé
Pino 3
Aciona o circuito de potência da bomba
Sensor de Solo
Pino 2
Lê o estado de umidade (Digital)
Sensor LDR
Pino A0
Lê o nível de luminosidade do ambiente (Analógico)

⚙️ Como o Código Funciona
O código realiza leituras contínuas a cada 1 segundo (1000 ms) e aplica uma lógica condicional:
Leitura da Umidade: O pino digital 2 lê se o solo está seco.
Leitura da Luz: O pino analógico A0 mede a claridade (de 0 a 1023). O limiar (limiteLuz) padrão está configurado em 500. Valores maiores indicam mais claridade.
Ação:
Se o solo estiver precisando de água E estiver claro o suficiente (luminosidade > limiteLuz), o relé é ativado (LOW, dependendo do módulo) e a irrigação começa.
Caso contrário, o relé permanece desativado (HIGH).
💻 Código Fonte
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

    // Debug no Monitor Serial
    Serial.print("Luminosidade: ");
    Serial.println(luminosidade);

    delay(1000);  // Verifica a cada 1 segundo
}


🚀 Como Executar
Conecte os componentes ao seu Arduino conforme a tabela de pinagem.
Abra a IDE do Arduino.
Copie o código acima e cole em um novo esboço (sketch).
Selecione a placa e a porta COM corretas no menu Ferramentas.
Faça o upload (carregamento) do código para o Arduino.
Abra o Monitor Serial (9600 baud) para acompanhar os valores de luminosidade e o status da irrigação.
💡 Próximos Passos e Melhorias
Calibrar o limiteLuz de acordo com o ambiente onde o sensor LDR será instalado.
Substituir o delay(1000) por millis() caso queira expandir o projeto para executar outras tarefas simultaneamente sem travar o loop.
