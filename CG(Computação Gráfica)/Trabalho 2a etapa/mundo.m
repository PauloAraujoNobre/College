function [vertCubo, facesCubo, ...
          vertTronco, facesTronco, ...
          vertParalelepipedo, facesParalelepipedo, ...
          vertPiramide, facesPiramide] = mundo()
  
  %A - CUBO
  [vertCubo, facesCubo] = calculaVertCubo();
   
  patch('Faces',facesCubo,'Vertices',vertCubo','FaceColor','r');  % Gerando o cubo
  hold on  %mantem o mesmpo plot

  %D - TRONCO
  [vertTronco, facesTronco] = calculaVertTronco();

  patch('Faces',facesTronco,'Vertices',vertTronco','FaceColor','c');  % Gerando o tronco
  hold on %serve para encerrar figura

  %B - PARALELEPIPEDO
  [vertParalelepipedo, facesParalelepipedo] = calculaVertParalelepipedo();

  patch('Faces',facesParalelepipedo,'Vertices',vertParalelepipedo','FaceColor','b');  % Gerando o paralelepipedo
  hold on  % mantem o mesmpo plot

  % C - PIRÂMIDE
  [vertPiramide, facesPiramide] = calculaVertPiramide();

  patch('Faces',facesPiramide,'Vertices',vertPiramide','FaceColor','g');  % Gerando o cubo

  %PLOTA OS DETALHES
  xlabel ("x");					        % configura o nome da vetor X
  ylabel ("y");					        % configura o nome da vetor Y
  zlabel ("z");					        % configura o nome da vetor Z
  grid();							          % inicia a plotagem com as linhas de grade
  axis([-6, 6, -6, 6, -6, 6]);
  view (15, 30);				      % determina o angulo inicial de visão da plotagem
  print -djpg q2mundo.jpg;		% salva o  como jpg
  hold off; 						        % serve para encerrar figura
endfunction