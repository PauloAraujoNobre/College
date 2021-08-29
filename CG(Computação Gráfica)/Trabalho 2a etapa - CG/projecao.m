function [cubo_projecao, faces_cubo, piramide_projecao, faces_piramide, paralelepipedo_projecao, faces_paralelepipedo, tronco_projecao, faces_tronco] = projecao()
  [cubo_camera, faces_cubo, piramide_camera, faces_piramide, paralelepipedo_camera, faces_paralelepipedo, tronco_camera, faces_tronco] = camera();
   
  clf;

  matriz_projecao = [1 0 0; 0 1 0; 0 0 0];

  cubo_projecao = cubo_camera * matriz_projecao;
  tronco_projecao = tronco_camera * matriz_projecao;
  paralelepipedo_projecao = paralelepipedo_camera * matriz_projecao;
  piramide_projecao = piramide_camera * matriz_projecao;

  patch('Faces', faces_cubo, 'Vertices', cubo_projecao, 'FaceColor', 'None', 'EdgeColor', 'b');
  patch('Faces', faces_tronco, 'Vertices', tronco_projecao, 'FaceColor', 'None', 'EdgeColor', 'g');
  patch('Faces', faces_paralelepipedo, 'Vertices', paralelepipedo_projecao, 'FaceColor', 'None', 'EdgeColor', 'r');
  patch('Faces', faces_piramide, 'Vertices', piramide_projecao, 'FaceColor', 'None', 'EdgeColor', 'c');

  xlabel ("x");
  ylabel ("y");
  zlabel ("z");
  grid();
  view (-30, 60);
  %print -djpg q4projecao.jpg;
  hold off;
endfunction