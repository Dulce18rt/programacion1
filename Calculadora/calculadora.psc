Algoritmo calculadora
	Definir a, b, resultado Como Real
	Definir opcion Como Entero
	Escribir 'Ingrese el primer n�mero: '
	Leer a
	Escribir 'Ingrese el segundo n�mero: '
	Leer b
	Escribir 'Seleccione una operaci�n:'
	Escribir '1. Suma'
	Escribir '2. Resta'
	Escribir '3. Multiplicaci�n'
	Escribir '4. Divisi�n'
	Leer opcion
	Seg�n opcion Hacer
		1:
			resultado <- a+b
			Escribir 'Resultado: ', resultado
		2:
			resultado <- a-b
			Escribir 'Resultado: ', resultado
		3:
			resultado <- a*b
			Escribir 'Resultado: ', resultado
		4:
			Si b<>0 Entonces
				resultado <- a/b
				Escribir 'Resultado: ', resultado
			SiNo
				Escribir 'Error: No se puede dividir entre 0.'
			FinSi
		De Otro Modo:
			Escribir 'Opci�n no v�lida.'
	FinSeg�n
FinAlgoritmo
