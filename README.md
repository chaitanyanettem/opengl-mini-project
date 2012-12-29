opengl-mini-project
=============

This is a college mini project that me and a friend have been working on for some time now.

It is a graphical implementation of the n-queens problem. This is the first time I have dealt with 
APIs so there are some minor problems.

Until then we have three files:

1. tmq1.c -> This works the best. However it has a fixed orthogonal and a reshape can't be implemented given that
we made the mistake of taking a positive orthogonal. So we are stuck without a reshape because of the positive 
orthogonal unless we rewrite the code.

2. tmq2.c -> This is a minor improvement. Just adds a title page. Not working at the moment.

3. tmq_v2b.c -> Here we rewrote a part of the code to make the orthogonal values variable. In theory this should be
working. However, it is not.

The fourth file, queen_bez.c is an early approximation of a queen we were going to use. It is created using Bezier
curves. The 3 bitmap images are used as textures to display Queens.
