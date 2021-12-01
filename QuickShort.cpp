#include <iostream> // metode pengurutan data menggunakan quick sort
using namespace std;

void show(int arr[], int size) // sebuah fungsi dimana nantinya akan digunakan untuk menampilkan semua data yg ada dalam array
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int partition(int arr[], int low, int high) // disini proses sorting tejadi. Pertama kita akan memilih pivot di ujung list, dan membandingkan setiap angka dari sebelah kiri dan kanan. Jika angka lebih kecil dari pivot maka ia akan ditempatkan di sebelah kiri & jika lebih besar maka akan ditempatkan di sebelah kanan. (angka paling kanan sebagai acuan proses sorting selanjutnya).
{
    int pivot = arr[high];
    int i = (low - 1); 

    for (int j = low; j < high; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) // disini kita membuat fungsi rekursif, pertama kita akan melakukan proses pivot jika angka masih belum tersorting secara ascending, maka kita akan terus menjalankan fungsinya hingga semua angka terurut sempurna.
{
    if (low < high)
    {

        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}


int main()
{
    int size;                               // pada line 47-54 digunakan untuk menampung array yang ingin diinputkan yang kemudian akan disorting
    cout << "\nMasukkan banyaknya data : ";

    cin >> size;

    int arr[size];

    cout << "\nMasukkan nilai data : ";

    for (int i = 0; i < size; ++i)      // 
    {
        cout << "\n";
        cin >> arr[i];
    }
    quickSort(arr, 0, size);    // disinilah fungsi quick sort dijalankan dan ditampilkan melalui fungsi yang telah kita buat sebelumnya yaitu fungsi show
    cout << "Sorted array\n";
    show(arr, size);
    return 0;
}