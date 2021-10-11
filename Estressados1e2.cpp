#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>

using namespace std;

//Busca

bool existe (vector<int> est, int valor){
    for (int i = 0; i < est.size(); i++){
        if (est[i] == valor) return true;
    }
    return false;
}

int contar (vector<int> est, int valor){
   int cont = 0;
   for (int i = 0; i < est.size(); i++){
      if (est[i] == valor) cont++;
   }
   return cont;
}

int procurar_valor (vector<int> est, int valor){
    for (int i = 0; i < est.size(); i++){
        if (est[i] == valor) return i;
    }
    return -1;
}

int procurar_valor_apartir (vector<int> est, int valor, int posicao){
    for (int i = posicao; i < est.size(); i++){
        if (est[i] == valor) return i;
    }
    return -1;
}

//Melhor Caso

int procurar_menor (vector<int> est){
   int min = 0;
   for (int i = 0; i < est.size(); i++){
      if (est[i] < est[min]) min = i;
   }
   return est[min];
}

int procurar_maior (vector <int> est){
   int max = 0;
   for (int i = 0; i < est.size(); i++){
      if (est[i] > est[max]) max = i;
   }
   return est[max];
}

int procurar_menor_pos (vector<int> est){
   int min = 0;
   for (int i = 0; i < est.size(); i++){
      if (est[i] < est[min]) min = i;
   }
   return min;
}

int procurar_menor_pos_apartir (vector<int> est, int pos){
   int menorApos = pos;
   for (int i = pos; i < est.size(); i++){
      if (est[i] < est[menorApos])
         menorApos = i;
   }
   return menorApos;
}

int procurar_melhor_pos_se (vector<int> est){
   int posHC = 0;
   for (int i = 0; i < est.size(); i++){
      if ((est[i] > 0) && (est[i] < est[posHC])) posHC = i;
   }
   if (est[posHC] > 0) return posHC;
   return -1;
}

//Contagem

float calcular_stress_medio (vector<int> est){
   float media = 0;
   for (int i = 0; i < est.size(); i++){
      if (est[i] < 0) media += est[i] * -1;
      else media += est[i];
   }
   media = media / est.size();
   return media;
}

string mais_homens_ou_mulheres (vector<int> est){
   int contM = 0;
   int contH = 0;
   for (int i = 0; i < est.size(); i++){
      if (est[i] > 0) contH++;
      else contM++;
   }
   if (contH == contM) return "empate";
   else if (contH > contM) return "homens";
   else return "mulheres";
}

string qual_metade_eh_mais_estressada (vector<int> est){
   int cont1 = 0;
   int cont2 = 0;
   for (int i = 0; i < est.size(); i++){
      if (i < (est.size() / 2)) cont1 += abs(est[i]);
      else cont2 += abs(est[i]);
   }
   if (cont1 == cont2) return "empate";
   else if (cont1 > cont2) return "primeira";
   else return "segunda";
}

bool homens_sao_mais_estressados_que_mulheres(vector<int> est){
   int contM = 0;
   int contH = 0;
   float mediaM = 0;
   float mediaH = 0;
   for (int i = 0; i < est.size(); i++){
      if (est[i] > 0){
         contH++;
         mediaH += est[i];
      }
      else{
         contM++;
         mediaM += est[i] * -1;
      }
   }
   mediaM = mediaM / contM;
   mediaH = mediaH / contH;
   
   if (mediaH > mediaM) return true;
   else return false;
}

//Filter

vector<int> clonar(const vector<int>& est){
    vector<int> copia;

    for (int i = 0; i < est.size(); i++) copia.push_back(est[i]);
    return copia;
}

vector<int> pegar_homens(const vector<int>& est){
    vector<int> lista_homens;

    for (int i = 0; i < est.size(); i++){
        if (est[i] > 0) lista_homens.push_back(est[i]);
    }    
    return lista_homens;
}

vector<int> pegar_calmos(const vector<int>& est){
    vector<int> homens_calmos;

    for (int i = 0; i < est.size();i++){
        if (est[i] < 10) homens_calmos.push_back(est[i]);
    }
    return homens_calmos;
}

vector<int> mulheres_calmas(const vector<int>& est){
    vector<int> mulheres_calmas;

    for(int i = 0; i < est.size(); i++){
        if (est[i] > -10 && est[i] <= -1) mulheres_calmas.push_back(est[i]);
    }
    return mulheres_calmas;
}

//Acesso

vector<int> inverter(const vector<int>& est){
    vector<int> copia_inversa;

    for(int i = 0; i < est.size(); i++){
        copia_inversa.push_back(est[i]);
    }
    reverse(copia_inversa.begin(), copia_inversa.end());
    
    return copia_inversa;
}

void inverter_inplace(vector<int>& est){
        reverse(est.begin(), est.end());
}

int sortear(const vector<int>& est){
    int k;
    srand(time(NULL));

    k = (rand() % 100);

    return est[k];
}

void embaralhar(vector<int>& est){
    srand(time(NULL));
    int aux;

    for (int i = 0; i < est.size(); i++){
        int x = rand() % est.size();
        aux = est[i];
        est[i] = est[x];
        est[x] = aux;
    }
}

void ordenar(vector<int>& est){
    int aux;

    for (int i = 0; i < est.size(); i++){
        for (int j = i + 1; j < est.size(); j++){
            aux = est[i];
            
            if(est[i] > est[j]){
            est[j] = est[i];
            est[j] = aux;
            }
        }
    }   
}

//Conjuntos

vector<int> exclusivos(const vector<int>& est){
    vector<int> sem_repeticao;

    int cont = 0;

    for (int i = 0; i < est.size(); i ++){
        for(int j = 0; j < est.size(); j++){
            if (i != j);
            else if (est[i] == est[j]) cont++;
        }
        if (cont = 0) sem_repeticao.push_back(est[i]);
    }
    return sem_repeticao;
}

vector<int> diferentes(const vector<int>& est){
    vector<int> diferentes;

    int cont = 0;

    for (int i = 0; i < est.size(); i++){
        for (int j = i + 1; j < est.size(); j++){
            if (i != j);
            else if (est[i] == est[j]) cont++;
        }
        if (cont == 0) diferentes.push_back(est[i]);
    }  
    return diferentes;
}

vector<int> abandonados(const vector<int>& v){
    vector<int> restante;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (i != j);
            else if (v[i] == v[j]) restante.push_back(v[i]);
        }
    }
    return restante;
}


int main() {
    
    //Busca

   cout << existe({-9, - 8, 3, 2, -98, 1}, 1) << "\n"; //true
   cout << existe({-9, - 8, 3, 2, -98, 1}, -1) << "\n"; //false

   cout << contar({1, 2, -98, 4, 5, 9, 12, 2, -3, 2}, 2) << "\n"; //3
   cout << contar({1, 2, -98, 4, 5, 9, 12, 2, -3}, 3) << "\n"; //0

   cout << procurar_valor({1, 3, 45, -9, -12, -99, 2, -99}, -99) << "\n"; //5
   cout << procurar_valor({1, 3, 45, -9, -12, -99, 2, -99}, -2) << "\n"; //-1

   cout << procurar_valor_apartir({1, 3, 45, -9, -12, -99, 2, -99}, -99, 6) << "\n"; //7
   cout << procurar_valor_apartir({1, 3, 45, -9, -12, -99, 2, -99}, 2, 5) << "\n"; //6


   //Melhor Caso

   cout << procurar_menor({1, -55, 12, 99, 87, -2, 7}) << "\n"; //-55

   cout << procurar_maior({1, -55, 12, 99, 87, -2, 7}) << "\n"; //99

   cout << procurar_menor_pos({1, -55, 12, 99, 87, -2, 7}) << "\n"; //1

   cout << procurar_menor_pos_apartir({1, -55, 12, 99, 87, -2, 7}, 3) << "\n"; //5

   cout << procurar_melhor_pos_se({5, -55, 12, 99, 87, 2, 7}) << "\n"; //5

   //Contagem 

   cout << calcular_stress_medio({5, -55, 10, 14, -20}) << "\n"; //20.8

   cout << mais_homens_ou_mulheres({5, -55, 10, 14, -20}) << "\n"; //homens
   cout << mais_homens_ou_mulheres({-55, 10, 14, -20}) << "\n"; //empate
   cout << mais_homens_ou_mulheres({5, -55, -10, 14, -20}) << "\n"; //mulheres

   cout << qual_metade_eh_mais_estressada({60, 3, -4, 9, 12, 33}) << "\n"; //primeira
   cout << qual_metade_eh_mais_estressada({66, 1, 2, 99, 5, 2}) << "\n"; //segunda
   cout << qual_metade_eh_mais_estressada({60, 2, 3, 5, 59, 1}) << "\n"; //empate

   cout << homens_sao_mais_estressados_que_mulheres({-5, -55, 70, 14}) << "\n"; //true
   cout << homens_sao_mais_estressados_que_mulheres({-55, 10, 14, -20}) << "\n";  //false

   vector<int> vector{60, 3, -4, 9, 12, 33};

   clonar(vector);
   
   pegar_homens(vector);
   
   pegar_calmos(vector);
   
   mulheres_calmas(vector);
   
   inverter(vector);
   
   inverter_inplace(vector);
   
   sortear(vector);
   
   embaralhar(vector);
   
   ordenar(vector);
   
   exclusivos(vector);
   
   diferentes(vector);
   
   abandonados(vector);

   return 0;
}