student(man, 5, slava).
student(man, 5, zhenya).
student(man, 4, sasha).
student(woman, 3, nika).
good(X):- 
    student(man, 5, X); 
    student(man, 4, X).

?-good(X).