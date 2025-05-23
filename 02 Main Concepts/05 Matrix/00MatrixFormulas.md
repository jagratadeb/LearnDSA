# Matrix Storage Formulas

## 1. Diagonal Matrix (`01CreateDiagonalMatrix.c`)
- Store only the diagonal elements (where row = column).
- **Formula:** `index = row - 1`
- Use when `row = column`

## 2. Lower Triangular Matrix (Row Major) (`02LowerTriangularRowMajor.c`)
- Store all elements on or below the main diagonal (`row >= column`).
- **Row major:** fill row by row.
- **Formula:** `index = row * (row - 1) / 2 + (column - 1)`

## 3. Lower Triangular Matrix (Column Major) (`03LowerTriangularColumnMajor.c`)
- Store all elements on or below the main diagonal (`row >= column`).
- **Column major:** fill column by column.
- **Formula:** `index = size * (column - 1) - (column - 2) * (column - 1) / 2 + (row - column)`

## 4. Upper Triangular Matrix (Row Major) (`04UpperTriangularRowMajor.c`)
- Store all elements on or above the main diagonal (`row <= column`).
- **Row major:** fill row by row.
- **Formula:** `index = (row - 1) * size - (row - 2) * (row - 1) / 2 + (column - row)`

## 5. Upper Triangular Matrix (Column Major) (`05UpperTrianglularColumnMajor.c`)
- Store all elements on or above the main diagonal (`row <= column`).
- **Column major:** fill column by column.
- **Formula:** `index = column * (column - 1) / 2 + (row - 1)`

## 6. Symmetric Matrix (`06SymmetricMatrix.c`)
- Store only the lower triangle, use symmetry to get any value.
- **Formula:**
  - If `row >= column`: `index = row * (row - 1) / 2 + (column - 1)`
  - If `row < column`:  `index = column * (column - 1) / 2 + (row - 1)`

## 7. Tridiagonal Matrix (`07TridiagonalMatrix.c`)
- Store only the main diagonal and the two next to it (just above and just below).
- **Formula:** `index = (row - 1) * 3 + (column - row + 1)`
- Use when `|row - column| <= 1`

## 8. Square Band Matrix (`08SquareBandMatrix.c`)
- Store the main diagonal and a few diagonals next to it (for example, two above and two below).
- **Formula:** `index = (row - 1) * (2 * d + 1) + (column - row + d)`
- `d` = number of diagonals above or below the main diagonal (`d = 1` for tridiagonal, `d = 2` for pentadiagonal)
- Use when `|row - column| <= d`

## 9. Toeplitz Matrix (`09ToeplitzMatrix.c`)
- Store only the first row and first column. Each diagonal (top-left to bottom-right) has the same value.
- **Formula:**
  - If `row <= column`: `index = column - row`
  - If `row > column`:  `index = row - column`

---
**Notes:**
- All row and column numbers start from 1.
- `size` means the number of rows or columns in the matrix.
- **Row major:** fill row by row. **Column major:** fill column by column.
- `d` = number of diagonals above or below the main diagonal you want to store.
