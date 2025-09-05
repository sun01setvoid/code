class Vector {
    int v[3];

    public:

        Vector (int a=0,int b=0,int   c=0){v[0]=a;v[1]=b;v[2]=c;}

        Vector& operator +(Vector & obj){

            for (int i=0;i<3;i++) v[i]=v[i]+obj.v[i];

                return *this;

          }

        Vector& operator *(Vector &obj){

            for (int i=0;i<3;i++) v[i]*=obj.v[i];

            return *this;

        }

};