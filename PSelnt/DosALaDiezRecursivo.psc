// Revisado por: Dulce Rocio Reyes Pirir
// Implementación del cálculo de una potencia mediante una función recursiva
// El paso recursivo se basa en que A^B = B*(A^(B-1))
// El paso base se base en que A^0 = 1
Función resultado <- Potencia (base,exponente)
	Si exponente=0 Entonces
		resultado <- 1
	SiNo
		resultado <- base*Potencia(base,exponente-1)
	FinSi
FinFunción

Algoritmo DosALaDiezRecursivo
	Escribir 'Ingrese Base'
	Leer base
	Escribir 'Ingrese Exponente'
	Leer exponente
	Escribir 'El resultado es ', Potencia(base,exponente)
FinAlgoritmo
