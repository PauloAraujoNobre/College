function [vert_cubo, faces_cubo] = cubo()
  p = [0 0 0];
  lado = 1.5;
  lado_metade = lado/2;

  vert_cubo_original = [ p(1)-lado_metade   p(2)-lado_metade   p(3) 	    1;
                         p(1)-lado_metade   p(2)+lado_metade   p(3) 		  1;
                         p(1)+lado_metade   p(2)+lado_metade   p(3) 		  1;
                         p(1)+lado_metade   p(2)-lado_metade   p(3) 		  1;
                         p(1)-lado_metade   p(2)-lado_metade   p(3)+lado  1;
                         p(1)-lado_metade   p(2)+lado_metade   p(3)+lado  1;
                         p(1)+lado_metade   p(2)+lado_metade   p(3)+lado  1;
                         p(1)+lado_metade   p(2)-lado_metade   p(3)+lado  1;]';

  matrix = [ 1  0  0  -5;
             0  1  0  4;
             0  0  1  -6];  

  vert_cubo = matrix * vert_cubo_original;

  faces_cubo = [1 2 3 4; 2 6 7 3; 4 3 7 8; 1 5 8 4; 1 2 6 5; 5 6 7 8]; 
  patch('Faces', faces_cubo, 'Vertices', vert_cubo', 'FaceColor','b');

  xlabel ("x");
  ylabel ("y");
  zlabel ("z");
  %axis([-0.75, 0.75, -0.75, 0.75, 0, 1.6]);
  grid();
  view (15, 30);
  print -djpg q1cubo.jpg;
  hold off; 
endfunction