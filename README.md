# Simulador de Caixa de Supermercado com Filas de Prioridade

Este é um programa em C que simula o atendimento de clientes em caixas de supermercado, utilizando o conceito de filas de prioridade. O sistema gerencia duas filas (uma comum e uma preferencial) e implementa uma lógica de atendimento alternada, além de gerar estatísticas sobre os atendimentos realizados.

## Funcionalidades

* **Duas Filas:** O sistema mantém uma Fila Comum e uma Fila Preferencial para clientes com prioridade legal (idosos, gestantes, PCD).
* **Cadastro de Clientes:**
    * **Interativo:** Permite cadastrar novos clientes inserindo nome, número de itens e indicando se possuem prioridade.
    * **Automático (Demonstração):** Clientes pré-definidos são carregados automaticamente ao iniciar o programa para facilitar testes.
* **Atendimento Alternado:** Os clientes são atendidos seguindo uma regra de "2 clientes comuns para 1 cliente preferencial".
* **Geração de Estatísticas:** Ao final do atendimento, é possível gerar estatísticas detalhadas, incluindo:
    * Número total de clientes atendidos.
    * Número de clientes atendidos por categoria (comum e preferencial).
    * Tempo médio de atendimento por tipo de fila (comum e preferencial), exibido em minutos e segundos.
    * Número total de itens processados.
* **Cálculo de Tempo de Atendimento:** Cada item de um cliente leva 5 segundos para ser processado, e o tempo total é exibido ao final do atendimento.
* **Liberação de Memória:** O programa garante a liberação de toda a memória alocada dinamicamente ao ser encerrado.

## Vídeo do sistema sendo executado

Para facilitar o entendimento do sistema, gravamos um vídeo demonstrando suas funcionalidades.
[Acesse o vídeo através desse link](https://youtu.be/UrPyiPX_ld4?si=-333aBw7uHbxTs1I)

## Estrutura do Projeto

O projeto é organizado nos seguintes arquivos:

* `main.c`: Contém a função `main` que gerencia o menu principal e a lógica de execução do programa.
* `clientes.h`: Define a estrutura `Cliente`, `NodeCliente` (nó para a fila), `NodeAtendido` (nó para a lista de atendidos) e `ListaAtendidos`, além do protótipo de `calcularTempo`.
* `clientes.c`: Implementa a função `calcularTempo`.
* `filas.h`: Contém as declarações das funções e estruturas relacionadas às filas (criação, inserção, atendimento, impressão) e à lista de clientes atendidos.
* `filas.c`: Implementa as funções de manipulação de filas e da lista de clientes atendidos, incluindo `exibirTempoFormatado`.
* `controller.h`: Declara as funções de controle, como `cadastrarCliente`, `cadastrarClienteDemo` e `gerarEstatisticas`.
* `controller.c`: Implementa as funções de controle, incluindo a lógica de cadastro e geração de estatísticas.
* `menu.h`: Declara as funções auxiliares do menu, como `handleOpcaoDois` (lógica de atendimento) e `handleOpcaoZero` (saída e liberação de memória).
* `menu.c`: Implementa as funções auxiliares do menu.

## Como Compilar e Executar (VS Code)

Para compilar e executar este programa no VS Code, siga os passos abaixo:

### Pré-requisitos

* **GCC (GNU Compiler Collection):** Certifique-se de ter um compilador C como o GCC instalado em seu sistema. No Windows, você pode usar o MinGW; no macOS, o Xcode Command Line Tools; e no Linux, ele geralmente já vem pré-instalado.
* **VS Code:** Instale o Visual Studio Code.
* **Extensões do VS Code:** Recomenda-se instalar as extensões "C/C++" (da Microsoft) e "Code Runner" (da Jun Han) para facilitar a compilação e execução.

### Passos

1.  **Abra a Pasta do Projeto:**
    * No VS Code, vá em `File > Open Folder...` (Arquivo > Abrir Pasta...) e selecione a pasta onde todos os arquivos do projeto (`.c` e `.h`) estão salvos.

2.  **Configure o Compilador (se necessário):**
    * Se for a primeira vez usando C/C++ no VS Code, pode ser necessário configurar o `tasks.json` para o GCC. A extensão C/C++ geralmente guia você. Para este projeto, você pode usar um `tasks.json` simples ou compilar via terminal.

3.  **Compile o Programa:**
    * Abra o Terminal Integrado no VS Code: `Terminal > New Terminal` (Terminal > Novo Terminal).
    * No terminal, navegue até a pasta do seu projeto se ainda não estiver nela (`cd nome_da_sua_pasta`).
    * Use o seguinte comando para compilar todos os arquivos `.c` e criar um executável:
        ```bash
        gcc main.c controller.c clientes.c filas.c menu.c -o supermercado
        ```
        * `gcc`: O compilador C.
        * `main.c controller.c clientes.c filas.c menu.c`: Todos os arquivos-fonte `.c` do seu projeto.
        * `-o supermercado`: Define o nome do arquivo executável de saída como `supermercado` (ou `supermercado.exe` no Windows).

4.  **Execute o Programa:**
    * Após a compilação bem-sucedida, você pode executar o programa diretamente do terminal:
        * No Linux/macOS:
            ```bash
            ./supermercado
            ```
        * No Windows (via Prompt de Comando ou PowerShell no VS Code):
            ```bash
            .\supermercado.exe
            ```

5.  **Usando o Code Runner (Opcional):**
    * Se você instalou a extensão "Code Runner", pode simplesmente abrir qualquer arquivo `.c` e clicar no ícone de "Play" (triângulo no canto superior direito do editor) ou usar o atalho `Ctrl+Alt+N`. O Code Runner detectará automaticamente os arquivos `.c` e tentará compilar e executar. No entanto, para múltiplos arquivos `.c`, o comando `gcc` manual é mais garantido ou você deve configurar o Code Runner para rodar o comando `gcc` completo.

## Fluxo de Uso do Programa

1.  **Início:** O programa pré-carrega alguns clientes automaticamente para facilitar a demonstração.
2.  **Menu Principal:** Um menu de opções será exibido:
    * **1 - Inserir cliente na fila (Interativo):** Permite adicionar um novo cliente fornecendo seus dados.
    * **2 - Atender cliente:** Atende o próximo cliente de acordo com a lógica de alternância (2 comuns, depois 1 preferencial).
    * **3 - Imprimir as filas:** Exibe o estado atual da fila preferencial e da fila comum.
    * **4 - Gerar estatísticas de atendimento:** Mostra dados como o número de clientes atendidos por tipo, tempo médio de atendimento e total de itens processados.
    * **0 - Sair:** Encerra o programa e libera a memória alocada.
3.  **Interação:** Digite o número da opção desejada e pressione Enter.
4.  **Estatísticas:** Experimente cadastrar e atender diferentes tipos de clientes para ver as estatísticas se atualizando.

---
**Desenvolvido por:** Clarissa Morita, Giovanna Dornelles, Isabella Vicente, João Victor e Peterson Fontinhas
