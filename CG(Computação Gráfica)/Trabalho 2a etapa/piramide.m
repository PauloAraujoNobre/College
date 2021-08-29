function [vert_piramide, faces_piramide] = piramide()
  p = [0 0 0];
  lado = 2;
  lado_meio = lado/2;
  h = 3;

  vert_piramide_original = [  p(1)-lado_meio   p(2)-lado_meio   p(3)   1;
                              p(1)-lado_meio   p(2)+lado_meio   p(3)   1;
                              p(1)+lado_meio   p(2)+lado_meio   p(3)   1;
                              p(1)+lado_meio   p(2)-lado_meio   p(3)   1;
                              p(1)             p(2)             p(3)+h 1]';
            
  ang = 45*pi/180;

  matrix = [ cos(ang)  -sin(ang)  0  -2;
             sin(ang)  cos(ang)   0  4;
             0          0         1  -6];
  
  vert_piramide = matrix * vert_piramide_original;
  faces_piramide = [1 2 5 5; 2 3 5 5; 3 4 5 5; 4 1 5 5; 1 2 3 4];
  patch('Faces', faces_piramide, 'Vertices', vert_piramide', 'FaceColor','c'); 

  xlabel ("x");
  ylabel ("y");
  zlabel ("z");
  grid();
  view (15, 30);
  print -djpg q1piramide.jpg;
  hold off; 
endfunction