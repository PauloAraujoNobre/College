function [vert_tronco, faces_tronco] = tronco()
  p = [0 0 0];
  base = 3;			
  topo = 1.3;		
  diff_b_t = (base-topo)/2;

  h = 2.5;							

  vert_tronco_original = [ p(1)                 p(2)                 p(3)    1;
                           p(1)                 p(2)+base            p(3)    1;
                           p(1)+base            p(2)+base            p(3)    1;
                           p(1)+base            p(2)                 p(3)    1;
                           p(1)+diff_b_t        p(2)+diff_b_t        p(3)+h  1;
                           p(1)+diff_b_t        p(2)+diff_b_t+topo   p(3)+h  1;
                           p(1)+diff_b_t+topo   p(2)+diff_b_t+topo   p(3)+h  1;
                           p(1)+diff_b_t+topo   p(2)+diff_b_t        p(3)+h  1; ]';


  matrix = [ 1  0  0  -6;
             0  1  0  -6;
             0  0  1  -6];

  vert_tronco = matrix * vert_tronco_original;
  faces_tronco = [1 2 3 4; 2 6 7 3; 4 3 7 8; 1 5 8 4; 1 2 6 5; 5 6 7 8];
  patch('Faces', faces_tronco, 'Vertices', vert_tronco', 'FaceColor','g');

  xlabel ("x");
  ylabel ("y");
  zlabel ("z");
  grid();	
  view (15, 30);
  print -djpg q1tronco.jpg;
  hold off; 
endfunction
