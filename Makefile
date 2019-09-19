CC = gcc
CFLAGS = 
ODIR = obj
LIBS = -lm

_OBJ = RunGaussianElimination.o GaussianElimination.o BackSubstitution.o MatrixType.o PrintMatrix.o RowCheck.o CheckingNonPivots.o TraceExchange.o SwapCols.o ZeroRows.o SwapZeroRows.o SwapRows.o ConvertRREF.o FindNullspace.o ZeroMatrix.o SetPrecision.o ParticularSolution.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

execute: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)