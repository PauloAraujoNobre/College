  function [cubo_camera, faces_cubo, piramide_camera, faces_piramide, paralelepipedo_camera, faces_paralelepipedo, tronco_camera, faces_tronco] = camera()

  [vert_cubo, faces_cubo, vert_tronco, faces_tronco, vert_paralelepipedo, faces_paralelepipedo, vert_piramide, faces_piramide] = mundo();

  clf;

  ponto_camera = [4; 2; -6];
                
  centro_cubo = [ (max(vert_cubo(1,:)) + min(vert_cubo(1,:)))/2
                  (max(vert_cubo(2,:)) + min(vert_cubo(2,:)))/2
                  (max(vert_cubo(3,:)) + min(vert_cubo(3,:)))/2
                ];
  
  centro_piramide = [ (max(vert_piramide(1,:)) + min(vert_piramide(1,:)))/2
                      (max(vert_piramide(2,:)) + min(vert_piramide(2,:)))/2
                      (max(vert_piramide(3,:)) + min(vert_piramide(3,:)))/2
                    ];

  ponto_medio = [ (centro_cubo(1) + centro_piramide(1))/2
                  (centro_cubo(2) + centro_piramide(2))/2
                  (centro_cubo(3) + centro_piramide(3))/2
                ];
                
  vetor_n = [ponto_camera, ponto_medio];

  aux = [-4; 6; 3];
  proj_aux_n = ((aux' * vetor_n)/dot(vetor_n, vetor_n)) * vetor_n; 
  vetor_u = aux - proj_aux_n;

  vetor_v = cross(vetor_n, vetor_u);

  vetor_n = vetor_n / sqrt(dot(vetor_n, vetor_n));
  vetor_u = vetor_u / sqrt(dot(vetor_u, vetor_u));
  vetor_v = vetor_v / sqrt(dot(vetor_v, vetor_v));

  base_camera = [vetor_n'; vetor_u'; vetor_v'];

  cubo_camera =  vert_cubo' * inv(base_camera);
  tronco_camera = vert_tronco' * inv(base_camera);
  paralelepipedo_camera = vert_paralelepipedo' * inv(base_camera);
  piramide_camera = vert_piramide' * inv(base_camera);

  patch('Faces', faces_cubo, 'Vertices', cubo_camera, 'FaceColor', 'b');
  patch('Faces', faces_tronco, 'Vertices', tronco_camera, 'FaceColor', 'g'); 
  patch('Faces', faces_paralelepipedo, 'Vertices', paralelepipedo_camera, 'FaceColor', 'r'); 
  patch('Faces', faces_piramide, 'Vertices', piramide_camera, 'FaceColor', 'c');

  xlabel ("x");
  ylabel ("y");
  zlabel ("z");
  grid();
  view (-30, 60);
  %print -djpg q3camera.jpg;
  hold off; 		
end