
function [cubo_projecao, facesCubo,...
          piramide_projecao, facesPiramide,... 
          paralelepipedo_projecao, facesParalelepipedo,... 
          tronco_projecao, facesTronco] = projecao()
  
  % pontos do sistema de coordenadas da câmera
  [cubo_camera, facesCubo,...
   piramide_camera, facesPiramide,... 
   paralelepipedo_camera, facesParalelepipedo,... 
   tronco_camera, facesTronco] = camera();
   
  % fecha figura
  clf;

  % matriz do plano pra projeção dos sólidos
  matriz_projecao = [1 0 0; 0 1 0; 0 0 0];

  cubo_projecao = cubo_camera * matriz_projecao;
  tronco_projecao = tronco_camera * matriz_projecao;
  paralelepipedo_projecao = paralelepipedo_camera * matriz_projecao;
  piramide_projecao = piramide_camera * matriz_projecao;

  patch('Faces',facesCubo,'Vertices',cubo_projecao,'FaceColor','None', 'EdgeColor', 'r');
  patch('Faces',facesTronco,'Vertices',tronco_projecao,'FaceColor','None', 'EdgeColor', 'c');
  patch('Faces',facesParalelepipedo,'Vertices',paralelepipedo_projecao,'FaceColor','None', 'EdgeColor', 'b');
  patch('Faces',facesPiramide,'Vertices',piramide_projecao,'FaceColor','None', 'EdgeColor', 'g');

  xlabel ("x");					        % configura o nome da vetor X
  ylabel ("y");					        % configura o nome da vetor Y
  zlabel ("z");					        % configura o nome da vetor Z
  grid();							          % inicia a plotagem com as linhas de grade
  view (0, 90);				          % determina o angulo inicial de visão da plotagem
  print -djpg q4projecao.jpg;		% salva o  como jpg
  hold off;  
endfunction