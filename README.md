# Analizador Léxico para Problemas de Optimización en C

Este repositorio contiene un **analizador léxico** escrito en C, diseñado para procesar expresiones de problemas de optimización lineal en formato texto. El programa convierte una secuencia de caracteres en tokens significativos, como operadores, variables y números, preparando la información para su posterior análisis o procesamiento en algoritmos de optimización.

---

## Estructura del Proyecto

- `lexer.c`  
  Implementa la función principal `lexer()` que realiza el análisis léxico sobre un archivo de texto de entrada.

- `lexer.h`  
  Contiene la definición de los tipos de tokens y la declaración de la función `lexer()`.

- `main.c`  
  Programa principal que invoca al analizador léxico pasándole un archivo como argumento.

- `algo.txt`  
  Archivo de ejemplo que representa un problema de optimización lineal.

---

## Tokens Reconocidos

El analizador reconoce los siguientes elementos:

| Símbolo | Token           | Descripción |
|---------|----------------|-------------|
| `+`     | `suma`         | Operador de suma |
| `-`     | `resta`        | Operador de resta |
| `Z`     | `var`          | Variable objetivo |
| `x`     | `var_opt`      | Variable de decisión |
| `=`     | `eq`           | Operador igualdad |
| `<`     | `lt`           | Operador menor que |
| `>`     | `gt`           | Operador mayor que |
| `<=`    | `lq`           | Operador menor o igual que |
| `>=`    | `gq`           | Operador mayor o igual que |
| `Número`| `number`       | Constantes numéricas |

---

## Compilación

Se recomienda compilar el proyecto con `gcc`:

```bash
gcc main.c lexer.c -o lexer
```

Esto generará un ejecutable llamado `lexer`.

---

## Uso

Para analizar un archivo de problemas de optimización:

```bash
./lexer algo.txt
```

El programa procesará línea por línea y mostrará por consola los **tokens reconocidos** y los **estados del autómata** durante el análisis.

Ejemplo de salida parcial:

```
state: 1, c: +, last state: 0
+
state: 8, c: 2, last state: 0
2
state: 6, c: Z, last state: 0
Z
```

Si el analizador encuentra un carácter inesperado, mostrará un mensaje de error:

```
Error
```

---

## Cómo Funciona

1. El analizador lee el archivo carácter por carácter.  
2. Mantiene un **estado** interno que determina cómo interpretar cada carácter.  
3. Reconoce operadores, números y variables siguiendo un **autómata finito determinista (AFD)**.  
4. Los tokens válidos se imprimen en consola cuando se completa su lectura.  
5. Si se encuentra un carácter inválido o inesperado, el analizador retorna un error y detiene la ejecución.