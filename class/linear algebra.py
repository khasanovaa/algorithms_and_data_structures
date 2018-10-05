from copy import deepcopy
from sys import stdin


class MatrixError(BaseException):
    def __init__(self, Matrix, mat1):
        self.matrix1 = Matrix
        self.matrix2 = mat1


class Matrix:
    def __init__(mat, a):
        mat.a = deepcopy(a)

    def __str__(mat):
        strMat = ''
        for i in range(len(mat.a)):
            strMat += ('\t'.join(map(str, mat.a[i])))
            if i != len(mat.a) - 1:
                strMat += '\n'
        return strMat

    def size(mat):
        return (len(mat.a), len(mat.a[0]),)

    def __add__(mat, mat2):
        if(mat.size() == mat2.size()):
            ansMat = []
            for i in range(len(mat2.a)):
                list1 = []
                for j in range(len(mat2.a[i])):
                    list1.append(mat2.a[i][j] + mat.a[i][j])
                ansMat.append(list1)
            return Matrix(ansMat)
        else:
            raise MatrixError(mat, mat2)

    def __mul__(mat, x):
        if isinstance(x, int) or isinstance(x, float):
            ansMat = []
            for i in range(len(mat.a)):
                list1 = []
                for j in range(len(mat.a[i])):
                    list1.append(mat.a[i][j] * x)
                ansMat.append(list1)
            return Matrix(ansMat)
        elif (isinstance(x, Matrix)):
            if(len(mat.a[0]) == len(x.a)):
                ansmat = []
                for i in range(len(mat.a)):
                    list1 = []
                    for j in range(len(x.a[0])):
                        res = 0
                        for k in range(len(mat.a[0])):
                            res += mat.a[i][k] * x.a[k][j]
                        list1.append(res)
                    ansmat.append(list1)
                return Matrix(ansmat)
            else:
                raise MatrixError(mat, x)
    __rmul__ = __mul__

    def transpose(mat):
        matsz = mat.size()
        mattr = []
        for i in range(matsz[1]):
            list1 = []
            for j in range(matsz[0]):
                list1.append(mat.a[j][i])
            mattr.append(list1)
        mat.a = deepcopy(mattr)
        return mat

    @staticmethod
    def transposed(mat):
        matsz = mat.size()
        mattr = []
        for i in range(matsz[1]):
            list1 = []
            for j in range(matsz[0]):
                list1.append(mat.a[j][i])
            mattr.append(list1)
        return Matrix(mattr)

    def replace(mat, b, x, y):
        (mat.a[x], mat.a[y]) = (mat.a[y], mat.a[x])
        (b[x], b[y]) = (b[y], b[x])

    def mult(mat, b, x, k):
        for i in range(len(mat.a)):
            mat.a[x][i] = mat.a[x][i] * k
            b[i] = b[i] * k

    def multplus(mat, b, x, y, k):
        for i in range(len(mat.a)):
            mat.a[y][i] += mat.a[x][i] * k
        b[y] += b[x] * k

    def solve(mat, b):
        n = len(mat.a)
        for i in range(n):
            if(mat.a[i][i] == 0):
                flag = 0
                for j in range(i + 1, n):
                    if mat.a[j][i] != 0 and flag == 0:
                        mat.multplus(b, j, i, 1)
            for j in range(n):
                if j != i and mat.a[i][i] != 0:
                    mat.multplus(b, i, j, (-mat.a[j][i] / mat.a[i][i]))
        q = 1
        for i in range(n):
            q *= mat.a[i][i]
        if q != 0:
            for i in range(n):
                b[i] = b[i] / mat.a[i][i]
            return b
        else:
            raise MatrixError(Matrix(), Matrix())


class SquareMatrix(Matrix):
    def __pow__(mat, n):
        if(n == 0 or n == 1):
            return mat
        elif n % 2 == 0:
            qq = pow(mat, n // 2)
            return qq * qq
        elif n % 2 == 1:
            qq = pow(mat, n // 2)
            return (qq) * qq * mat

exec(stdin.read())
