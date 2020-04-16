create table DataDasar(
id int primary key identity(1,1),
nama varchar(50),
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

create table MasterIndikator(
id int primary key identity(1,1),
id_pembilang int,
id_penyebut int,
nama varchar(50),
deskripsi varchar(50),
default_bobot float,
create_date datetime,
last_update datetime,
expired_date datetime,
constraint fk_pembilang foreign key(id_pembilang)
	references DataDasar(id),
constraint fk_penyebut foreign key(id_penyebut)
	references DataDasar(id)
)

create table Periode(
id int identity(1,1) primary key,
nama varchar(50),
create_date datetime,
last_update datetime
)


create table Indikator_Periode(
id_master int unique,
id_periode int unique,
bobot float,
constraint fk_master foreign key(id_master)
	references MasterIndikator(id),
constraint fk_periode foreign key(id_periode)
	references Periode(id)

)
create table SatuanKerja(
id int identity(1,1),
id_satker as 'SK'+ RIGHT('00000000000000000000000000000' + CAST(ID AS varCHAR(30)), 30) PERSISTED primary key,
id_ins_satker int,
id_induk_satker varchar(32),
nama varchar(50),
email varchar(50),
create_date datetime,
last_update datetime,
expired_date datetime,
constraint fk_ins_satker foreign key(id_ins_satker)
	references JenisSatker(id),
constraint fk_induk_satker foreign key(id_induk_satker)
	references SatuanKerja(id_satker)
)

create table Capaian_Unit(
id_satker varchar(32),
id_datadasar int,
waktu datetime,
capaian float,
constraint fk_satker foreign key(id_satker)
	References SatuanKerja(id_satker) on delete cascade,
constraint fk_datadasar foreign key(id_datadasar)
	References DataDasar(id) on delete cascade
)

create table Indikator_SatuanKerja(
id_periode int unique,
id_master integer unique,
id_satker varchar(32) unique,
bobot float,
target float,
capaian float,
last_update datetime,
constraint fk_periode1 foreign key (id_periode) 
	references Indikator_Periode(id_periode)
	, 
constraint fk_master1 foreign key (id_master) 
	references Indikator_Periode(id_master)
	,
constraint fk_satker1 foreign key (id_satker) 
	references SatuanKerja(id_satker)
	
)

create table Indikator_SatuanKerja_Log(
id_periode int,
id_master integer,
id_satker varchar(32),
capaian float,
create_date datetime,
constraint fk_periode2 foreign key (id_periode) 
	references Indikator_SatuanKerja(id_periode)
	, 
constraint fk_master2 foreign key (id_master) 
	references Indikator_SatuanKerja(id_master)
	,
constraint fk_satker2 foreign key (id_satker) 
	references Indikator_SatuanKerja(id_satker)
	
)
