// GLEW fornece acesso às funções da OpenGL
#include <GL/glew.h>
// GLFW fornece todas as constantes, tipos e protótipos de função da API
#include <GLFW/glfw3.h>
#include <iostream>

// Função principal, aonde o programa é inicializado
int main() {

  // Verificação e inicialização do glfw
  if (!glfwInit()) {
    // Caso não inicializar, imprimi uma mensagem de erro no terminal e subsequente para o programa retornando -1
    std::cerr << "Erro ao inicializar GLFW" << std::endl;
    return -1;
  }
  
  // Caso a Verificação a cima for verdaderia cria-se uma nova janela "window"
  GLFWwindow *window = glfwCreateWindow(800, 600, "Voxel", NULL, NULL);

  // Verifica se a janela foi criada com sucesso
  if (!window) {
    // Se a criação falhar imprimi uma mensagem de erro no terminal e usa a função "glfwTerminate" para destróir todas as janelas existentes
    std::cerr << "Erro ao criar janela" << std::endl;
    glfwTerminate();
    // Após isso, termina o programa retornando -1
    return -1;
  }

  // Diz ao OpenGL qual janela (e contexto gráfico) deve usar agora e torna o contexto "ativo" em uma thread específica
  // Aonde todos os comandos OpenGL vão afetar está janela "window"
  glfwMakeContextCurrent(window);

  // Verificação e inicialização do glew
  if (glewInit() != GLEW_OK) {
    // Se glewInit() retornar "GLEW_OK", a inicialização foi bem-sucedida, caso não imprimi uma mensagem de erro no terminal
    std::cerr << "Erro ao inicializar GLEW" << std::endl;
    // Após isso, termina o programa retornando -1
    return -1;
  }

  // Depois de todas as verificações bem-sucedidas o loop da janela principal é criado caso a função retornar um sinalizador
  // "glfwWindowShouldClose" verifica se a janela (window) "deve ser fechada" sinalizando 1 ou 0
  while (!glfwWindowShouldClose(window)) {

    // Específica os valores usados para limpar os buffers de cor (buffers de cor é basicamente a "tela" aonde a OpenGL desenha)
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    // Limpa os buffers usando os valores predefinidos à cima
    glClear(GL_COLOR_BUFFER_BIT);

    // Inverte os buffers frontal e traseiro da janela (mostra na tela o que foi desenhado no frame atual)
    // Buffer traseiro -> onde é desenhado tudo do frame atual
    // Buffer frontal -> o que aparece na tela para o usuário
    glfwSwapBuffers(window);
    // Processa os eventos que já aconteceram, como: Teclado, Mouse, Fechamento da janela, Redimensionamento da janela, Outros eventos do sistema de janelas
    // lê os eventos que já ocorreram e chama os callbacks correspondentes
    glfwPollEvents();
  }

  // Após o loop da janela, destrói todas as janelas existentes e retorna 0
  glfwTerminate();
  return 0;
}
