function [vert_cubo, faces_cubo, vert_tronco, faces_tronco, vert_paralelepipedo, faces_paralelepipedo, vert_piramide, faces_piramide] = mundo()

  [vert_cubo, faces_cubo] = cubo();
  patch('Faces',faces_cubo,'Vertices',vert_cubo','FaceColor','r');

  [vert_tronco, faces_tronco] = tronco();
  patch('Faces',faces_tronco,'Vertices',vert_tronco','FaceColor','c');

  [vert_paralelepipedo, faces_paralelepipedo] = paralelepipedo();
  patch('Faces',faces_paralelepipedo,'Vertices',vert_paralelepipedo','FaceColor','b');

  [vert_piramide, faces_piramide] = piramide();
  patch('Faces',faces_piramide,'Vertices',vert_piramide','FaceColor','g');

  xlabel ("x");
  ylabel ("y");
  zlabel ("z");
  grid();
  axis([-6, 6, -6, 6, -6, 6]);
  view (15, 30);
  %print -djpg q2mundo.jpg;
  hold off;
endfunction