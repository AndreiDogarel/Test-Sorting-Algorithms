<h1>Proiectul 1 Structuri de Date - <b>Algoritmi de Sortare</b></h1>

<h2>Scurtă prezentare:</h2>
<p>În acest proiect sunt realizate următoarele:</p>
<ol>
  <li>Implementarea următorilor algoritmi:
     <ul>
       <li><a href = "https://github.com/AndreiDogarel/Test-Sorting-Algorithms/blob/main/MergeSort.cpp">MergeSort</a></li>
       <li><a href = "https://github.com/AndreiDogarel/Test-Sorting-Algorithms/blob/main/QuickSort.cpp">QuickSort</a></li>
       <li><a href = "https://github.com/AndreiDogarel/Test-Sorting-Algorithms/blob/main/RadixSortBitwise.cpp">RadixSort (cu diferite baze puteri ale lui 2)</a></li>
       <li><a href = "https://github.com/AndreiDogarel/Test-Sorting-Algorithms/blob/main/RadixSortB10.cpp">RadixSort (în baza 10)</a></li>
       <li><a href = "https://github.com/AndreiDogarel/Test-Sorting-Algorithms/blob/main/CountSort.cpp">CountSort</a></li>
       <li><a href = "https://github.com/AndreiDogarel/Test-Sorting-Algorithms/blob/main/ShellSort.cpp">ShellSort</a></li>
     </ul>
  </li>
  <li>Testarea timpului de execuție pentru fiecare algoritm în parte cu diferite input-uri:
    <ul>
       <li>Permutări ale mulțimii {1, ... , N} - distribuție: uniformă</li>
       <li>Permutări ale mulțimii {1, ... , N} - distribuție: aproape sortate</li>
       <li>Mulțimi de N numere generate random
         <p><b>Notă: </b>pentru numerele generate random sunt alese diferite range-uri: [1000, 100000], [100000, 100000000], [100000000, INT_MAX].</p>
       </li>
    </ul>
  </li>
</ol>

<h2>Modul de testare al timpului de execuție:</h2>
<p>Fiecare algoritm sortează de 3 ori un vector atribuit de funcția corespunzătoare tipului de test și este luat minimul dintre cei 3 timpi de execuție (în secunde).</p>
