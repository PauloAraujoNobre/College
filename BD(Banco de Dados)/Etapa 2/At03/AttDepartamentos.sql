CREATE database Departamentos;

USE Departamentos;

CREATE TABLE Departamentos (
	idDepartamentos int,
    Departamento varchar(45),
    PRIMARY KEY (idDepartamentos)
);

CREATE TABLE Disciplinas (
	idDisciplinas int,
    Disciplina varchar(45),
    CargaHoraria int,
    Departamentos_idDepartamentos int,
    PRIMARY KEY (idDisciplinas),
    FOREIGN KEY (Departamentos_idDepartamentos) REFERENCES Departamentos(idDepartamentos)
);

INSERT INTO Departamentos (idDepartamentos, Departamento) values (1, 'Departamento 1');

INSERT INTO Departamentos (idDepartamentos, Departamento) values (2, 'Departamento 2');

INSERT INTO Disciplinas (idDisciplinas, Disciplina, CargaHoraria, Departamentos_idDepartamentos) values (1, 'Disciplina 1', 80, 1);

INSERT INTO Disciplinas (idDisciplinas, Disciplina, CargaHoraria, Departamentos_idDepartamentos) values (2, 'Disciplina 2', 60, 2);

UPDATE Departamentos set Departamento = 'update Departamento' where idDepartamentos = 1;

DELETE FROM Disciplinas WHERE idDisciplinas = 2;