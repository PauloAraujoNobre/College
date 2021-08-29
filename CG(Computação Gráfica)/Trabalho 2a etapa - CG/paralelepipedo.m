function [vert_paralelepipedo, faces_paralelepipedo] = paralelepipedo()
  p = [0 0 0];
  lado_x = 1.5;
  lado_y = 5.0;
  lado_z = 2.5;

  vert_paralelepipedo_original = [ 	p(1)           p(2)           p(3)          1;
                                    p(1)           p(2)+lado_y   p(3)          1;
                                    p(1)+lado_x   p(2)+lado_y   p(3)          1;
                                    p(1)+lado_x   p(2)           p(3)          1;
                                    p(1)           p(2)           p(3)+lado_z  1;
                                    p(1)           p(2)+lado_y   p(3)+lado_z  1;
                                    p(1)+lado_x   p(2)+lado_y   p(3)+lado_z  1;
                                    p(1)+lado_x   p(2)           p(3)+lado_z  1;]';

  matrix = [  1  0  0  -2 ;
              0  1  0  -6 ;
              0  0  1  -6 ];

  vert_paralelepipedo = matrix * vert_paralelepipedo_original;
  faces_paralelepipedo = [1 2 3 4; 2 6 7 3; 4 3 7 8; 1 5 8 4; 1 2 6 5; 5 6 7 8];
  
  patch('Faces', faces_paralelepipedo, 'Vertices', vert_paralelepipedo', 'FaceColor','r');

  xlabel ("x");
  ylabel ("y");
  zlabel ("z");
  %axis([0, 1.5, 0, 5, 0, 2.5]);
  grid();
  view (15, 30);
  %print -djpg q1paralelepipedo.jpg;
  hold off; 
endfunction