using namespace std;

struct nodo{
    int dato;
    nodo * sig;
    nodo * ant;
}*ptr;

void cabeza(nodo *& ptr,int dato){
    nodo * p = new nodo;
    p->dato = dato;
    if(ptr == NULL){
        p->sig = ptr;
        p->ant = ptr;
        ptr = p;
    }else{
        ptr->ant = p;
        p->sig = ptr;
        p->ant = NULL;
        ptr=p;
    }
}

void  recorrer(nodo *& ptr){
    if(ptr != NULL){
        cout<<"["<<ptr->dato<<"]"<<"->";
        recorrer(ptr->sig);
    }else{cout<<"NULL";}
}

void cola(nodo *& ptr,int dato){
    if(ptr == NULL){
        cabeza(ptr,dato);
    }else{
        if(ptr->sig == NULL){
        nodo *p = new nodo;
        p->dato = dato;
        ptr->sig = p;
        p->ant = ptr;
        p->sig = NULL;
        }else{
            cola(ptr->sig,dato);
        }
    }
}

void eliminar(nodo *&ptr , int dato){
    bool x = false;
    if(ptr == NULL){
        cout<<"> "<<"Lista Vacia"<<endl;
    }else{
        if(ptr->dato==dato){
            if(ptr->ant == NULL and ptr->sig==NULL){
                delete(ptr);
                x =  true;
                cout<<"> "<<"Elemento Eliminado"<<endl;
                ptr = NULL;
            }else{
                if(ptr->ant == NULL){
                    nodo *p;
                    p = ptr->sig;
                    p->ant = NULL;
                    ptr->sig = NULL;
                    ptr->ant = NULL;
                    delete(ptr);
                    ptr = p;
                    x = true;
                    cout<<"> "<<"Elemento Eliminado"<<endl;
                }else{
                    nodo *p,*j;
                    p = ptr->ant;
                    j = ptr->sig;
                    ptr->sig = NULL;
                    ptr->ant = NULL;
                    delete ptr;
                    p->sig = j;
                    if(j!=NULL){j->ant = p;}
                    x = true;
                    cout<<"> "<<"Elemento Eliminado"<<endl;
                }
            }

        }else{
            if(ptr->sig == NULL){
                if(x==false){cout<<"> "<<"elemento no encontrado"<<endl;}
            }else{eliminar(ptr->sig,dato);}
        }
    }
}

void buscar(nodo *& ptr , int dato){
    if(ptr != NULL){
        if(ptr->dato == dato){
            cout<<"> "<<"Elemento encotrado : "<<dato<<endl;
        }else{buscar(ptr->sig,dato);}
    }else{cout<<"> "<<"Dato no encontrado"<<endl;}
}

int po(int a , int b){
    if(ptr != NULL){
        if(b==1){
            return a;
        }else if(b==0){
            return 1;
        }else{
            return a * po(a,b-1);
        }
    }
}

void rec(nodo *& ptr){
    if(ptr != NULL){
        cout<<po(ptr->dato,ptr->dato)<<"-> ";
        rec(ptr->sig);
    }
};

void invertida(nodo *& ptr){
    if(ptr != NULL){
        invertida(ptr->sig);
        cout<<"["<<ptr->dato<<"]"<<"-> ";
    }
}

int factorial(int n){
    if(n == 0 or n == 1){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

int producto(int a , int b){
    if(b==1){
        return a;
    }else{
        return a + producto(a,b-1);
    }
}

int fibonacci(int n){
    if(n == 0 or n==1){
        return n;
    }else{
        return fibonacci(n-2) + fibonacci(n-1);
    }
}

int recf(nodo *& ptr){
    if(ptr!=NULL){
        cout<<fibonacci(ptr->dato)<<"->";
        recf(ptr->sig);
    }else{cout<<"NULL";}
}

bool loop(){
    bool x = false;
        cout<<"   ====================================================================="<<endl;
        cout<<"   =  1-> Insertar nodo  cabeza            9-> Producto                ="<<endl;
        cout<<"   =  2-> Insertar nodo  cola              f-> Fibonacci               ="<<endl;
        cout<<"   =  3-> Recorrer                          x-> salir                  ="<<endl;
        cout<<"   =  4-> Buscar                                                       ="<<endl;
        cout<<"   =  5-> eliminar                                                     ="<<endl;
        cout<<"   =  6-> Datos a la potencia                                          ="<<endl;
        cout<<"   =  7-> Mostrar lista invertida                                      ="<<endl;
        cout<<"   =  8-> Factorial                                                    ="<<endl;
        cout<<"   ====================================================================="<<endl;
        char j ;
        cout<<endl<<"> ";cin>>j;
        switch(j){
            case 'x':
                x = true;
                system("clear");
                break;
            case '1':
                cout<<"> "<<"ingrese el dato: ";
                int dato;
                cin>>dato;
                if(cin.fail() && cin.rdstate()){
                    cout<<"> "<<"no has ingresado un entero, intenalo de nuevo :(";
                    cin.clear();
                    cin.ignore().get();
                }else{
                    cout<<"> "<<"Dato registrado";
                    cabeza(ptr,dato);
                    cin.get();
                }
                cin.ignore();
                break;

            case '2':
                cout<<"> "<<"ingrese el dato: ";
                cin>>dato;
                if(cin.fail() && cin.rdstate()){
                    cout<<"> "<<"no has ingresado un entero, intenalo de nuevo :(";
                    cin.clear();
                    cin.ignore().get();
                }else{
                    cout<<"> "<<"Dato registrado";
                    cola(ptr,dato);
                    cin.get();
                }
                cin.ignore();
                break;

            case '3':
                recorrer(ptr);
                cin.ignore().get();
                break;

            case '4':
                    cout<<"> "<<"ingrese el dato a buscar: ";
                    cin>>dato;
                    if(cin.fail()){
                        cout<<"> "<<"no has ingresado un entero, intenalo de nuevo :(";
                        cin.clear();
                        cin.ignore().get();
                    }else{
                        buscar(ptr,dato);
                        cin.get();
                    }
                    cin.ignore();
                    break;

            case '5':
                cout<<"> "<<"Ingrese el dato a eliminar: ";
                cin>>dato;
                    if(cin.fail()){
                        cout<<"> "<<"no has ingresado un entero, intenalo de nuevo :(";
                        cin.clear();
                        cin.ignore().get();
                    }else{
                        eliminar(ptr,dato);
                        cin.get();
                    }
                    cin.ignore();
                    break;
            case'6':
                cout<<"> ";
                rec(ptr);
                cin.ignore().get();
                break;
            case'7':
                cout<< "> ";
                invertida(ptr);
                cin.ignore().get();
                break;
            case'8':
                cout<<"> "<<"ingrese dato : ";
                cin>>dato;
                if(cin.fail()){
                    cin.clear();
                    cout<<"> "<<"no has ingresado un entero, intenalo de nuevo :(";
                    cin.ignore().get();
                    }else{
                        cout<<"> "<<factorial(dato);
                        cin.get();
                    }
                    cin.ignore();
                break;
            case '9':
                int a,b;
                cout<<"> "<<"ingrese primero digito ";cin>>a;
                cout<<"> "<<"ingrese segundo digito ";cin>>b;
                if(cin.fail()){
                    cin.clear();
                    cout<<endl;
                    cout<<"> "<<"no has ingresado un entero, intenalo de nuevo :(";
                    cin.ignore().get();
                    }else{
                        cout<<"> "<<producto(a,b);
                        cin.get();
                    }
                    cin.ignore();
                break;
            case 'f':
                    cout<<"> ";
                    recf(ptr);
                    cin.ignore().get();

        }
        system("clear");
    return x;
}

