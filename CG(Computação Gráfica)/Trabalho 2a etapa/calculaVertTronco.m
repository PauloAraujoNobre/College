function [vertTronco, facesTronco] = calculaVertTronco()
  %D - TRONCO
  p1 = [0 0 0];                 % ponto inicial
  base = 3;						        % base do tronco
  topo = 1.3;						        % topo do tronco
  mdif = (base-topo)/2;         % metade da diferença entre a base e o topo
  tdif = topo+mdif;				      % variavel para calcular os pontos do topo do tronco                    
  h = 2.5;							          % altura do tronco

  %montando os pontos do tronco
  vertTroncoOriginal = [ p1(1)        p1(2)        p1(3)    1;
                         p1(1)        p1(2)+base   p1(3)    1;
                         p1(1)+base   p1(2)+base   p1(3)    1;
                         p1(1)+base   p1(2)        p1(3)    1;
                         p1(1)+mdif   p1(2)+mdif   p1(3)+h  1;
                         p1(1)+mdif   p1(2)+tdif   p1(3)+h  1;
                         p1(1)+tdif   p1(2)+tdif   p1(3)+h  1;
                         p1(1)+tdif   p1(2)+mdif   p1(3)+h  1; ]';

  %Matriz de transformação
  mtPa = [ 1  0  0  -6;
           0  1  0  -6;
           0  0  1  -6];

  vertTronco = mtPa*vertTroncoOriginal;
  facesTronco = [1 2 3 4; 2 6 7 3; 4 3 7 8; 1 5 8 4; 1 2 6 5; 5 6 7 8];
  
  patch('Faces',facesTronco,'Vertices',vertTronco','FaceColor','g');
  
  %PLOTA OS DETALHES
  xlabel ("x");					        % configura o nome da vetor X
  ylabel ("y");					        % configura o nome da vetor Y
  zlabel ("z");					        % configura o nome da vetor Z
  grid();							          % inicia a plotagem com as linhas de grade
  view (15, 30);				        % determina o angulo inicial de visão da plotagem
  print -djpg q1tronco.jpg;		  % salva o  como jpg
  hold off; 
endfunction
