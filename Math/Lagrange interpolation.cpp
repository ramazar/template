//f(x) = Sum of i = 1 → i = n + 1 yi * (Mul of j != i (x – xj) / (xi – xj))
//this is O(n^2) which is slow
//optimization:
//let xi = i , yi = f(i)
//then f(x) will be equal to:
//ai = (x – 1) * (x – 2) * … * (x – i + 1) * (x – i – 1) * … * (x – n)
//bi = (-1)n-i * (n – i)! * (i – 1)!
//f(x) = Sum of yi * ai / bi
