function [vertPiramide, facesPiramide] = calculaVertPiramide()
  % C - PIRÂMIDE
  p1 = [0 0 0];               % ponto inicial
  uni = 2;                  % unidades do tamanho da base 
  meio = uni/2;   			      % metade da unidade
  h = 3;							        % altura da piramide
  facesPiramide = [1, 2, 5; 2, 3, 5; 3, 4, 5; 4, 1, 5]; % as 4 faces da piramide

  % montando os pontos da base da pirâmide
  vertPiramideOriginal = [  p1(1)-meio   p1(2)-meio   p1(3)   1;
                            p1(1)-meio   p1(2)+meio   p1(3)   1;
                            p1(1)+meio   p1(2)+meio   p1(3)   1;
                            p1(1)+meio   p1(2)-meio   p1(3)   1;
                            p1(1)        p1(2)        p1(3)+h 1]';
            
  % transformação em rotação  + translação da base da piramide
  ang = 45*pi/180; 	% angulo em radianos

  % Matriz de transformação
  mtR = [ cos(ang)  -sin(ang)  0  -2;
          sin(ang)  cos(ang)   0  4;
          0          0         1  -6];
          
  vertPiramide = mtR*vertPiramideOriginal;
  facesPiramide = [1 2 5 5; 2 3 5 5; 3 4 5 5; 4 1 5 5; 1 2 3 4];
  
  patch('Faces',facesPiramide,'Vertices',vertPiramide','FaceColor','c'); 
  
  %PLOTA OS DETALHES
  xlabel ("x");					        % configura o nome da vetor X
  ylabel ("y");					        % configura o nome da vetor Y
  zlabel ("z");					        % configura o nome da vetor Z
  grid();							          % inicia a plotagem com as linhas de grade
  view (15, 30);				        % determina o angulo inicial de visão da plotagem
  print -djpg q1piramide.jpg;		% salva o  como jpg
  hold off; 
endfunction