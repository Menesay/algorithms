
# Greedy

* local optimum = global optimum olan problemledir
* mesela sürekli seçilebilinecek en büyük elemanı seçmek

# coin problem
* {1,2,5,10,20,50,100} set of coininde n sayısını en az coin kullanarak elde etmek.
* greedy ile çözülebilir ve ömzümü sürekli seçilebilinecek en büyük elemanı seçmektir.
* 413 = 4 * 100 + 1 * 10 + 1 * 2 + 1 * 1 : 4 + 1 + 1 + 1 = 7 coin ile çözdük

* {1, 3, 4} gibi bir birbirinin katı olmayan bir set olsaydı, greedy çalışmazdı.
* 6 -> greedy ile -> 1 * 4 + 2 * 3 : 3 coin. oysaki 2 * 3 : 3 coin