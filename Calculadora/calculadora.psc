Algoritmo calculadora
	Definir a, b, resultado Como Real
	Definir opcion Como Entero
	Escribir 'Ingrese el primer número: '
	Leer a
	Escribir 'Ingrese el segundo número: '
	Leer b
	Escribir 'Seleccione una operación:'
	Escribir '1. Suma'
	Escribir '2. Resta'
	Escribir '3. Multiplicación'
	Escribir '4. División'
	Leer opcion
	Según opcion Hacer
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
			Escribir 'Opción no válida.'
	FinSegún
FinAlgoritmo
