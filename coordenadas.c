#include "coordenadas.h"
#include <math.h>
#include <stdio.h>

/// multiplica um vetor por um escalar
/// este é um exemplo entregue pronto pra você ;)
vetor multiplicaPorEscalar(vetor v, escalar alpha)
{
    vetor resultado =
    {
        v.x * alpha,
        v.y * alpha,
        v.z * alpha,
        v.w * alpha
    };
    return resultado;
}

vetor somaVetorComVetor(vetor v, vetor u)
{
    v.x+=u.x;
    v.y+=u.y;
    v.z+=u.z;
    v.w+=u.w;
    vetor resultado = v;
    return resultado;
}

vetor diferencaVetorComVetor(vetor v, vetor u)
{
    v.x-=u.x;
    v.y-=u.y;
    v.z-=u.z;
    v.w-=u.w;
    vetor resultado = v;
    return resultado;
}

vetor diferencaEntrePontos(ponto p, ponto q)
{
    vetor resultado = {p.x-q.x,p.y-q.y,p.z-q.z,p.w-q.w};
    return resultado;
}

ponto somaPontoComVetor(ponto p, vetor v)
{
    p.x+=v.x;
    p.y+=v.y;
    p.z+=v.z;
    p.w+=v.w;
    ponto resultado = p;
    return resultado;
}

escalar normaDoVetor(vetor v)
{
    escalar resultado = pow(v.x,2)+pow(v.y,2)+pow(v.z,2)+pow(v.w,2);
    resultado = pow(resultado,0.5);
    return resultado;
}

vetor normalizado(vetor v)
{
    escalar resultad = pow(v.x,2)+pow(v.y,2)+pow(v.z,2)+pow(v.w,2);
    resultad = pow(resultad,0.5);
    v.x/=resultad;
    v.y/=resultad;
    v.z/=resultad;
    v.w/=resultad;
    vetor resultado = v;
    return resultado;
}

escalar distanciaEntrePontos(ponto p, ponto q)
{
    escalar resultado = pow(p.x-q.x,2)+pow(p.y-q.y,2)+pow(p.z-q.z,2)+pow(p.w-q.w,2);
    resultado = pow(resultado,0.5);
    return resultado;
}

escalar produtoEscalar(vetor v, vetor u)
{
    v.x*=u.x;
    v.y*=u.y;
    v.z*=u.z;
    v.w*=u.w;
    escalar resultado = v.x+v.y+v.z+v.w;
    return resultado;
}

vetor produtoVetorial(vetor v, vetor u)
{
    double a,b,c;
    a = v.y*u.z - v.z*u.y;
    b = v.z*u.x - v.x*u.z;
    c = v.x*u.y - v.y*u.x;
    v.x=a;
    v.y=b;
    v.z=c;
    vetor resultado = v;
    return resultado;
}

///
/// Referências: http://localhost:8080/classes/geometry/#30
escalar anguloEntreVetores(vetor v, vetor u)
{
    escalar t =produtoEscalar(v,u);
    escalar coseno=t/(normaDoVetor(v)*normaDoVetor(u));
    escalar resultado = acos(coseno);
    return resultado;
}

///
/// Referências: http://localhost:8080/classes/geometry/#22
ponto combinacaoAfim2Pontos(ponto p, ponto q, escalar alpha)
{
    q=diferencaEntrePontos(q,p);
    q=multiplicaPorEscalar(q,alpha);
    p=somaPontoComVetor(p,q);
    ponto resultado = p;
    return resultado;
}

/// Imprime um vetor ou ponto no terminal
/// Uso:
///   vetor r = somaVetorComVetor(a, b);
///   imprime("vetor r", r);
void imprime(struct coordenadas c, char* nome)
{
    printf("%s = { %.2f, %.2f, %.2f, %.2f }\n", nome, c.x, c.y, c.z, c.w);
}
