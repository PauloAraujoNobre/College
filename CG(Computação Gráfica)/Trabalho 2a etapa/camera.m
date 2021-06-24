function [cubo_camera, facesCubo,...
          piramide_camera, facesPiramide,... 
          paralelepipedo_camera, facesParalelepipedo,... 
          tronco_camera, facesTronco] = camera()
  
  %pontos do sistema de coordenadas do mundo
  [vertCubo, facesCubo, ...
   vertTronco, facesTronco,...
   vertParalelepipedo, facesParalelepipedo, ...
   vertPiramide, facesPiramide] = mundo();
  
  %fecha figuras anteriores
  clf;
  
  %ponto da câmera
  ponto_camera = [1; 1; 1];

  %calculando centros de massa do cubo e tronco
  centro_cubo = [ (max(vertCubo(:,1)) + min(vertCubo(:,1)))/2
                  (max(vertCubo(:,2)) + min(vertCubo(:,2)))/2
                  (max(vertCubo(:,3)) + min(vertCubo(:,3)))/2
                 ];
                 
  centro_tronco = [ (max(vertTronco(:,1)) + min(vertTronco(:,1)))/2
                    (max(vertTronco(:,2)) + min(vertTronco(:,2)))/2
                    (max(vertTronco(:,3)) + min(vertTronco(:,3)))/2
                  ];

  %calculando ponto médio entre os centros de massa
  ponto_medio = [ (centro_cubo(1) + centro_tronco(1))/2
                  (centro_cubo(2) + centro_tronco(2))/2
                  (centro_cubo(3) + centro_tronco(3))/2
                ];
                
  %calculando vetor n do SCC: n = eye - at
  camera_n = ponto_camera - ponto_medio;

  %calculando vetor u da câmera, usando projeção de aux em n
  aux = [1; 10; 15];
  proj_aux_n = ((aux' * camera_n)/dot(camera_n, camera_n)) * camera_n;
  camera_u = aux - proj_aux_n;

  %calculando vetor v da camera, usando produto vetorial de n e u
  camera_v = cross(camera_n, camera_u);

  %noramlizando os vetores n, u e v
  camera_n = camera_n / sqrt(dot(camera_n, camera_n));
  camera_u = camera_u / sqrt(dot(camera_u, camera_u));
  camera_v = camera_v / sqrt(dot(camera_v, camera_v));

  %formando matriz de base da câmera
  base_camera = [camera_n'; camera_u'; camera_v'];

  %mudança de base nas coordenadas dos objetos
  cubo_camera =  vertCubo' * inv(base_camera);
  tronco_camera = vertTronco' * inv(base_camera);
  paralelepipedo_camera = vertParalelepipedo' * inv(base_camera);
  piramide_camera = vertPiramide' * inv(base_camera);

  %desenhando objetos
  patch('Faces',facesCubo,'Vertices',cubo_camera,'FaceColor','r');
  patch('Faces',facesTronco,'Vertices',tronco_camera,'FaceColor','c'); 
  patch('Faces',facesParalelepipedo,'Vertices',paralelepipedo_camera,'FaceColor','b'); 
  patch('Faces',facesPiramide,'Vertices',piramide_camera,'FaceColor','g');

  %PLOTA OS DETALHES
  xlabel ("x");					        % configura o nome da vetor X
  ylabel ("y");					        % configura o nome da vetor Y
  zlabel ("z");					        % configura o nome da vetor Z
  grid();							          % inicia a plotagem com as linhas de grade
  view (15, 30);				      % determina o angulo inicial de visão da plotagem
  print -djpg q3camera.jpg;		% salva o  como jpg
  hold off; 		
end