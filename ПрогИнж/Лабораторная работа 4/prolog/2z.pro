fr(X) :- 
    Z is sin(X^2) - cos(X^2),
    write(Z).

?-fr(1)