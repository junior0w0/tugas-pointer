#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<windows.h>

#define COUT(x) std::cout<<x;
#define CIN(x) std::cin>>x;
#define GETLINE(x) std::getline(std::cin,x,'\n');

void pengisianDataMahasiswa(std::string* nama, std::string* NIM){
  COUT("Isikan nama: ");
  GETLINE(*nama);
  COUT("Isikan NIM: ");
  GETLINE(*NIM);
}



int main(){
  int jumlahMakul=10;

  std::string makul[10]={"Pancasila","Komunikasi Data","Kalkulus","Hardware dan Software","Bahasa Inggris",
                          "Struktur Data","Pemrograman","Agama","Grafik","Sistem Operasi"};
  int nilaiMakul[10];
  int jumlahDataMahasiswa=0;

  std::vector<std::string> namaMahasiswa;
  std::vector<std::string> NIMMahasiswa;
  std::vector<double> IPKMahasiswa;

  bool lanjut = true;
  while(lanjut){
    int index = 0;
    int temp;
    std::string tempNama;
    std::string tempNIM;
    double IPK = 0.0;
    char pilih;

    pengisianDataMahasiswa(&tempNama, &tempNIM);
    
    for (size_t i = 0; i < jumlahMakul; i++){
      COUT("Inputkan nilai untuk makul "<<makul[i]<<" : ");
      CIN(temp);
      switch (temp){
      case 81 ... 100:
        nilaiMakul[i]=4;
        break;
      case 60 ... 80:
        nilaiMakul[i]=3;
        break;
      case 40 ... 59:
        nilaiMakul[i]=2;
        break;
      case 20 ... 39:
        nilaiMakul[i]=1;
        break;
      case 0 ... 19:
        nilaiMakul[i]=0;
        break;  
      default:
        break;
      }
    }
  
    for (size_t i = 0; i < jumlahMakul; i++){
    IPK+=nilaiMakul[i];
    }

    IPK/=jumlahMakul;
    IPK=std::ceil(IPK * 100.0)/100.0;

    namaMahasiswa.push_back(tempNama);
    NIMMahasiswa.push_back(tempNIM);
    IPKMahasiswa.push_back(IPK);

    COUT("Apakah masih ingin menginput?(Y/N)\n")
    CIN(pilih);
    std::cin.ignore();

    if (pilih == 'Y'){
      continue;
    }
    else if(pilih == 'N'){
      lanjut = false;
    }else {
      lanjut = false;
    }
    index++;
    system("CLS");

  }
  
  COUT("\n");

  for (size_t i = 0; i < namaMahasiswa.size(); i++)
  {
    COUT("Data ke-"<<i+1<<"\n");
    COUT("Nama mahasiswa: "<<namaMahasiswa[i]<<"\n");
    COUT("NIM: "<<NIMMahasiswa[i]<<"\n");
    COUT("IPK: "<<IPKMahasiswa[i]<<"\n");
  }
  



  return 0;
}
