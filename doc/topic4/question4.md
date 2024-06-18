# **Хеш-таблицы. Понятие коллизии.**
>**Хеш-табли́ца** (англ. hash-table) — структура данных, реализующая интерфейс ассоциативного массива. В отличие от деревьев поиска, реализующих тот же интерфейс, обеспечивают меньшее время отклика в среднем. Представляет собой эффективную структуру данных для реализации словарей, а именно, она позволяет хранить пары (ключ, значение) и выполнять три операции: операцию добавления новой пары, операцию поиска и операцию удаления пары по ключу.

Особенность этой структуры данных в том, что стандартные операции: вставка, чтение и удаление данных, она, в среднем, выполняет за константное время **O(1)**, то есть, быстро и не зависимо от размера таблицы (объема данных):

![](https://i.imgur.com/yjgw3Tf.png)

Существуют два основных варианта хеш-таблиц: с **открытой адресацией** и [**списками**](Метод&#32;цепочек(открытое&#32;хеширование).md "Метод цепочек"). Хеш-таблица является массивом элементы которого есть пары (хеш-таблица с открытой адресацией) или списки пар (хеш-таблица со списками).

Выполнение операции в хеш-таблице начинается с вычисления хеш-функции от ключа. Получающееся хеш-значение
```i = hash(key)```

играет роль индекса в массиве ```H[]```. Затем выполняемая операция (добавление, удаление или поиск) перенаправляется объекту, который хранится в соответствующей ячейке массива. Затем выполняемая операция (добавление, удаление или поиск) перенаправляется объекту, который хранится в соответствующей ячейке массива ```H[i]```


Ситуация, когда для различных ключей получается одно и то же хеш-значение, называется коллизией. Такие события не так уж и редки — например, при вставке в хеш-таблицу размером 365 ячеек всего лишь 23 элементов вероятность коллизии уже превысит 50% (если каждый элемент может равновероятно попасть в любую ячейку). Поэтому механизм разрешения коллизий — важная составляющая любой хеш-таблицы.

В некоторых специальных случаях удаётся избежать коллизий вообще. Например, если все ключи элементов известны заранее (или очень редко меняются), то для них можно найти некоторую совершенную хеш-функцию, которая распределит их по ячейкам хеш-таблицы без коллизий. Хеш-таблицы, использующие подобные хеш-функции, не нуждаются в механизме разрешения коллизий, и называются хеш-таблицами с прямой адресацией.

> Число хранимых элементов, делённое на размер массива ```H[]``` (число возможных значений хеш-функции), называется **коэффициентом заполнения хеш-таблицы** (load factor) и является важным параметром, от которого зависит среднее время выполнения операций.

