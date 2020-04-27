create table DataDasar(
id int primary key identity(1,1),
nama varchar(500),
create_date datetime,
last_update datetime,
expired_date datetime
)

create table JenisSatker(
id int primary key identity(1,1),
nama varchar(50),
create_date datetime,
last_update datetime,
expired_date datetime
)

create table Aspek(
	id int identity(1,1) primary key,
	aspek varchar(50),
	komponen_aspek varchar(100)
)
create table MasterIndikator(
id int primary key identity(1,1),
id_aspek int,
id_pembilang int,
id_penyebut int,
nama varchar(1000),
deskripsi varchar(1000),
default_bobot float,
create_date datetime,
last_update datetime,
expired_date datetime,
constraint fk_pembilang foreign key(id_pembilang)
	references DataDasar(id),
constraint fk_penyebut foreign key(id_penyebut)
	references DataDasar(id),
constraint fk_aspek FOREIGN key(id_aspek)
	references Aspek(id)
)

create table Periode(
id int identity(1,1) primary key,
nama varchar(50),
create_date datetime,
last_update datetime
)


create table Indikator_Periode(
id int identity(1,1) primary key,
id_master int ,
id_periode int ,
bobot float,
constraint fk_master foreign key(id_master)
	references MasterIndikator(id),
constraint fk_periode foreign key(id_periode)
	references Periode(id)

)
create table SatuanKerja(
id varchar(32) primary key,
id_ins_satker int,
id_induk_satker varchar(32),
nama varchar(1000),
email varchar(50),
create_date datetime,
last_update datetime,
expired_date datetime,
constraint fk_ins_satker foreign key(id_ins_satker)
	references JenisSatker(id),
constraint fk_induk_satker foreign key(id_induk_satker)
	references SatuanKerja(id)
)

create table Capaian_Unit(
id_satker varchar(32),
id_datadasar int,
waktu datetime,
capaian float,
constraint fk_satker foreign key(id_satker)
	References SatuanKerja(id) on delete cascade,
constraint fk_datadasar foreign key(id_datadasar)
	References DataDasar(id) on delete cascade
)

create table Indikator_SatuanKerja(
id int identity(1,1) primary key,
id_indikator_periode int,
id_satker varchar(32),
bobot float,
target float,
capaian float,
last_update datetime,
constraint fk_periode1 foreign key (id_indikator_periode) 
	references Indikator_Periode(id)
	,
constraint fk_satker1 foreign key (id_satker) 
	references SatuanKerja(id)
	
)

create table Indikator_SatuanKerja_Log(
id_indikator_satker int,
capaian float,
create_date datetime,
constraint fk_indikator_satker foreign key (id_indikator_satker) 
	references Indikator_SatuanKerja(id)
)
