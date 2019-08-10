#include <iostream>
#include <fstream>
#define inf 2147483647
using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
int n,m,a,b,c;
struct nod{
    int vecin;
    int cost;
    struct nod *urm;
}*l[50001],*q;//liste cu drumurile care pornesc din fiecare nod si valoarea lor
int viz[50001];//are valoarea 0 daca nodul nu a fost vizitat si pozitia sa in heap in caz contrar
int h[50001],nr;//heapul si numarul de elemente din acesta
int d[50001],mn;//distantele pana la fiecare nod si nodul minim curent

void add_h(int nr){
    //incepem de pe pozitia curenta
    int poz=nr;
    //cat timp mai exista noduri in heap si tatal are distanta mai mare decat fiul
    while(poz>1 && d[h[poz/2]]>d[h[poz]]){
        //interschimbam tatal cu fiul
        swap(h[poz/2],h[poz]);
        //interschimbam pozitiile acestora in vectorul viz
        swap(viz[h[poz/2]],viz[h[poz]]);

        //continuam cautarea pentru noul tata
        poz/=2;
    }
}
void del_vf(int &nr){
    //interschimbam primul cu ultimul elemente si scadem numarul de elemente din heap
    h[1]=h[nr];
    swap(viz[h[1]],viz[h[nr]]);
    --nr;
    //incepem cautarea din radacina
    int poz=1;
    while(2*poz<=nr){
        int fiu=2*poz;
        //daca exista descendent drept si are distanta mai mica decat cel stang, il consideram fiu optim
        if(fiu+1<=nr && d[h[fiu+1]]<d[h[fiu]])
            ++fiu;
        //daca fiul optim are distanta mai mica decat tatal
        if(d[h[fiu]]<d[h[poz]]){
            //interschimbam tatal cu fiul
            swap(h[poz],h[fiu]);
            //interschimbam pozitiile acestora in vectorul viz
            swap(viz[h[poz]],viz[h[fiu]]);

            //continuam cautarea pentru fiu
            poz=fiu;
        }
        //atfel oprim cautarea
        else poz=nr+1;
    }
}
void dijkstra(int p){
    //initializam toate distantele cu +inf
    for(int i=2;i<=n;++i)
        d[i]=inf;
    //parcurgem nodurile care au drum din primul nod
    for(q=l[p];q!=NULL;q=q->urm){
        //modificam distanta in vector
        d[q->vecin]=q->cost;
        //crestem numarul de elemente din heap si il adaugam pe ultima pozitie
        ++nr;
        viz[q->vecin]=nr;
        h[nr]=q->vecin;
        //ne asiguram sa pastram proprietatea de heap
        add_h(nr);
    }

    while(nr>0){
        //scoatem radacina(elementul minim) din heap si o marcam ca nevizitata
        mn=h[1];
        viz[mn]=0;
        //ne asiguram sa pastram proprietatea de heap
        del_vf(nr);
        //parcurgem nodurile care au drum din nodul minim
        for(q=l[mn];q!=NULL;q=q->urm){
            //daca distanta prin drumul minim este mai mica
            if(d[q->vecin]>d[mn]+q->cost){
                //actualizam distanta
                d[q->vecin]=d[mn]+q->cost;
                //adaugam nodul in heap daca nu exista deja in acesta
                if(viz[q->vecin]==0){
                    ++nr;
                    viz[q->vecin]=nr;
                    h[nr]=q->vecin;
                    add_h(nr);
                }
                //altfel ne asiguram ca nodul este intr-o pozitie corecta
                else
                    add_h(viz[q->vecin]);
            }
        }
    }
}
int main()
{
    //citim numarul de noduri si muchii
    in>>n>>m;
    //memoram drumurile si distantele acestora care incep din fiecare nod
    for(int i=1;i<=m;++i){
        in>>a>>b>>c;
        q=new nod;
        q->vecin=b;
        q->cost=c;
        //adaugam la sfarsitul listei
        q->urm=l[a];
        l[a]=q;
    }
    //stabilim distanta minima de la modul 1 catre toate celelalte noduri
    dijkstra(1);
    //afisam
    for(int i=2;i<=n;++i)
        if(d[i]!=inf)
            out<<d[i]<<" ";
        else
            out<<"0 ";
    return 0;
}
