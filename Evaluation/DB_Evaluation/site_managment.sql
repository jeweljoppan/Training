-- MySQL dump 10.13  Distrib 5.1.54, for Win32 (ia32)
--
-- Host: localhost    Database: site_managment
-- ------------------------------------------------------
-- Server version	5.1.54-community

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `controller`
--

DROP TABLE IF EXISTS `controller`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `controller` (
  `controller_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `controller_code` varchar(10) NOT NULL,
  `name` varchar(20) NOT NULL,
  `current_status` tinyint(1) NOT NULL DEFAULT '0',
  `current_site` int(10) unsigned DEFAULT NULL,
  `registered_by` int(10) unsigned DEFAULT NULL,
  `registration_time` datetime DEFAULT NULL,
  `url` varchar(50) NOT NULL,
  PRIMARY KEY (`controller_id`),
  UNIQUE KEY `controller_code` (`controller_code`),
  KEY `cur_site` (`current_site`),
  KEY `contr_detls_id` (`registered_by`),
  CONSTRAINT `contr_detls_id` FOREIGN KEY (`registered_by`) REFERENCES `user_details` (`details_id`),
  CONSTRAINT `cur_site` FOREIGN KEY (`current_site`) REFERENCES `site` (`site_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `controller`
--

LOCK TABLES `controller` WRITE;
/*!40000 ALTER TABLE `controller` DISABLE KEYS */;
INSERT INTO `controller` VALUES (1,'CR001','ID-8086',1,1,1,'2019-09-18 12:00:00','home/id/124'),(2,'CR002','ID-8085',0,2,1,'2019-07-15 01:30:00','home/room/8998'),(3,'CR003','ID-8008',1,4,1,'2018-07-10 10:30:00','studio/2323'),(4,'CR008','ID-I7',1,1,1,'2019-09-11 11:00:00','home/dinning/124');
/*!40000 ALTER TABLE `controller` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = latin1 */ ;
/*!50003 SET character_set_results = latin1 */ ;
/*!50003 SET collation_connection  = latin1_swedish_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER update_point_UPDATE
	AFTER UPDATE ON controller
	FOR EACH ROW
	BEGIN
		DECLARE status BOOLEAN;
		
		SELECT current_status 
		INTO @status
		FROM  controller
		WHERE controller_id = NEW.controller_id;

		UPDATE point
		SET current_status = @status
		WHERE controller = NEW.controller_id;
	END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `country`
--

DROP TABLE IF EXISTS `country`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `country` (
  `country_id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `country_name` varchar(20) NOT NULL,
  PRIMARY KEY (`country_id`),
  UNIQUE KEY `country_name` (`country_name`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `country`
--

LOCK TABLES `country` WRITE;
/*!40000 ALTER TABLE `country` DISABLE KEYS */;
INSERT INTO `country` VALUES (2,'Canada'),(1,'India');
/*!40000 ALTER TABLE `country` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `duty_assigned`
--

DROP TABLE IF EXISTS `duty_assigned`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `duty_assigned` (
  `duty_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `site` int(10) unsigned NOT NULL,
  `user_details` int(10) unsigned NOT NULL,
  PRIMARY KEY (`duty_id`),
  KEY `duty_site_id` (`site`),
  KEY `duty_detls_id` (`user_details`),
  CONSTRAINT `duty_site_id` FOREIGN KEY (`site`) REFERENCES `site` (`site_id`),
  CONSTRAINT `duty_detls_id` FOREIGN KEY (`user_details`) REFERENCES `user_details` (`details_id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `duty_assigned`
--

LOCK TABLES `duty_assigned` WRITE;
/*!40000 ALTER TABLE `duty_assigned` DISABLE KEYS */;
INSERT INTO `duty_assigned` VALUES (1,1,1),(3,4,2),(4,1,3),(5,1,4),(6,2,5),(7,3,6),(8,4,7),(9,4,8),(10,1,8),(11,4,1),(12,4,2),(13,1,7),(14,1,5);
/*!40000 ALTER TABLE `duty_assigned` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `point`
--

DROP TABLE IF EXISTS `point`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `point` (
  `point_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `type` tinyint(3) unsigned NOT NULL,
  `value` varchar(10) DEFAULT NULL,
  `last_update` datetime DEFAULT NULL,
  `controller` int(10) unsigned NOT NULL,
  `current_status` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`point_id`),
  KEY `pnt_type` (`type`),
  KEY `cntlrR_id` (`controller`),
  CONSTRAINT `cntlrR_id` FOREIGN KEY (`controller`) REFERENCES `controller` (`controller_id`),
  CONSTRAINT `pnt_type` FOREIGN KEY (`type`) REFERENCES `point_type` (`point_type_id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `point`
--

LOCK TABLES `point` WRITE;
/*!40000 ALTER TABLE `point` DISABLE KEYS */;
INSERT INTO `point` VALUES (1,'point one',1,'10101','2019-09-20 14:58:27',1,1),(2,'point two',2,'50','2019-09-20 15:00:15',2,0),(3,'third point',1,'123','2019-09-20 15:00:15',1,1),(4,'point X',1,'10','2019-09-20 17:02:03',2,1),(5,'point again',2,'550','2019-09-20 17:02:53',4,1);
/*!40000 ALTER TABLE `point` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `point_type`
--

DROP TABLE IF EXISTS `point_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `point_type` (
  `point_type_id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `type` varchar(20) NOT NULL,
  PRIMARY KEY (`point_type_id`),
  UNIQUE KEY `type` (`type`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `point_type`
--

LOCK TABLES `point_type` WRITE;
/*!40000 ALTER TABLE `point_type` DISABLE KEYS */;
INSERT INTO `point_type` VALUES (1,'Analog'),(2,'Digial');
/*!40000 ALTER TABLE `point_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `region`
--

DROP TABLE IF EXISTS `region`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `region` (
  `region_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `region_code` varchar(10) NOT NULL,
  `name` varchar(50) NOT NULL,
  `timezone` tinyint(3) unsigned DEFAULT NULL,
  PRIMARY KEY (`region_id`),
  UNIQUE KEY `region_code` (`region_code`),
  KEY `timezone_fk` (`timezone`),
  CONSTRAINT `timezone_fk` FOREIGN KEY (`timezone`) REFERENCES `timezone` (`timezone_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `region`
--

LOCK TABLES `region` WRITE;
/*!40000 ALTER TABLE `region` DISABLE KEYS */;
INSERT INTO `region` VALUES (1,'R001','South',1),(2,'R002','North',1),(3,'R003','Central Canada',3),(4,'R004','Eastern Canada',2);
/*!40000 ALTER TABLE `region` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `site`
--

DROP TABLE IF EXISTS `site`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `site` (
  `site_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `site_code` varchar(10) NOT NULL,
  `name` varchar(50) NOT NULL,
  `address_line_1` varchar(50) NOT NULL,
  `address_line_2` varchar(50) DEFAULT NULL,
  `state` smallint(5) unsigned NOT NULL,
  `country` tinyint(3) unsigned NOT NULL,
  `zipcode` varchar(8) NOT NULL,
  `description` varchar(150) DEFAULT NULL,
  `region` int(10) unsigned DEFAULT NULL,
  `timezone` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`site_id`),
  UNIQUE KEY `site_code` (`site_code`),
  KEY `state_id` (`state`),
  KEY `cntry_id` (`country`),
  KEY `rgion_id` (`region`),
  KEY `tm_zone_site` (`timezone`),
  CONSTRAINT `tm_zone_site` FOREIGN KEY (`timezone`) REFERENCES `timezone` (`timezone_id`),
  CONSTRAINT `cntry_id` FOREIGN KEY (`country`) REFERENCES `country` (`country_id`),
  CONSTRAINT `rgion_id` FOREIGN KEY (`region`) REFERENCES `region` (`region_id`),
  CONSTRAINT `state_id` FOREIGN KEY (`state`) REFERENCES `state` (`state_id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `site`
--

LOCK TABLES `site` WRITE;
/*!40000 ALTER TABLE `site` DISABLE KEYS */;
INSERT INTO `site` VALUES (1,'S001','Asset','Menamkulam',NULL,1,1,'682039','Flat',1,1),(2,'S002','Apple','Niagara',NULL,6,2,'45-45-3','Apartment',3,3),(3,'S003','Asten','Kakkanad',NULL,1,1,'682020','Villa',NULL,1),(4,'S004','L&T','Torronto',NULL,4,2,'46-46-46','Studio',NULL,1);
/*!40000 ALTER TABLE `site` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `state`
--

DROP TABLE IF EXISTS `state`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `state` (
  `state_id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `state_name` varchar(20) NOT NULL,
  `country_id` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`state_id`),
  UNIQUE KEY `state_name` (`state_name`),
  KEY `country_id` (`country_id`),
  CONSTRAINT `state_ibfk_1` FOREIGN KEY (`country_id`) REFERENCES `country` (`country_id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `state`
--

LOCK TABLES `state` WRITE;
/*!40000 ALTER TABLE `state` DISABLE KEYS */;
INSERT INTO `state` VALUES (1,'Kerala',1),(2,'Tamil Nadu',1),(3,'Karnataka',2),(4,'Torronto',2),(5,'Gujarat',1),(6,'Niagra',2);
/*!40000 ALTER TABLE `state` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `timezone`
--

DROP TABLE IF EXISTS `timezone`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `timezone` (
  `timezone_id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(64) NOT NULL,
  PRIMARY KEY (`timezone_id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `timezone`
--

LOCK TABLES `timezone` WRITE;
/*!40000 ALTER TABLE `timezone` DISABLE KEYS */;
INSERT INTO `timezone` VALUES (3,'CANADA/CTZ'),(2,'CANADA/ETZ'),(1,'IST');
/*!40000 ALTER TABLE `timezone` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user_details`
--

DROP TABLE IF EXISTS `user_details`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user_details` (
  `details_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `first_name` varchar(50) NOT NULL,
  `last_name` varchar(50) NOT NULL,
  `phone` bigint(20) unsigned NOT NULL,
  `role` tinyint(3) unsigned NOT NULL,
  `current_status` tinyint(1) NOT NULL DEFAULT '1',
  `user_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`details_id`),
  KEY `role_id` (`role`),
  KEY `usr_id` (`user_id`),
  CONSTRAINT `role_id` FOREIGN KEY (`role`) REFERENCES `user_role` (`role_id`),
  CONSTRAINT `usr_id` FOREIGN KEY (`user_id`) REFERENCES `user_login` (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user_details`
--

LOCK TABLES `user_details` WRITE;
/*!40000 ALTER TABLE `user_details` DISABLE KEYS */;
INSERT INTO `user_details` VALUES (1,'Abner','Biju',9495658797,1,1,1),(2,'John','Doe',7878459687,3,0,2),(3,'Harry','Williams',9877896556,2,1,3),(4,'Jane','Doe',9546896556,3,0,4),(5,'Iobe','Weles',9546789514,1,1,5),(6,'Jack','James',7896896556,2,1,6),(7,'Mathew','Perry',9000789514,3,1,7),(8,'Phillip','Joseph',8500789514,2,0,8);
/*!40000 ALTER TABLE `user_details` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user_login`
--

DROP TABLE IF EXISTS `user_login`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user_login` (
  `user_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `email` varchar(50) DEFAULT NULL,
  `password` varchar(50) NOT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user_login`
--

LOCK TABLES `user_login` WRITE;
/*!40000 ALTER TABLE `user_login` DISABLE KEYS */;
INSERT INTO `user_login` VALUES (1,'abc@gmail.com','qwert'),(2,'john@ymail.com','open'),(3,'harry@hotmail.com','123qwe'),(4,'jane123@gmail.com','werwer'),(5,'iopqwe@gmail.com','123qwesad'),(6,'jackj@gmail.com','poiioop'),(7,'mat@gmail.com','8787yui'),(8,'phillip@gmail.com','oiuytr');
/*!40000 ALTER TABLE `user_login` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user_role`
--

DROP TABLE IF EXISTS `user_role`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user_role` (
  `role_id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `role` varchar(20) NOT NULL,
  `view_all_access` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`role_id`),
  UNIQUE KEY `role` (`role`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user_role`
--

LOCK TABLES `user_role` WRITE;
/*!40000 ALTER TABLE `user_role` DISABLE KEYS */;
INSERT INTO `user_role` VALUES (1,'Admin',1),(2,'Manager',0),(3,'Viewer',0);
/*!40000 ALTER TABLE `user_role` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-09-20 17:10:21
