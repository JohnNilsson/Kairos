import sbt._
import de.element34.sbteclipsify._

class Kairos(info: ProjectInfo) extends DefaultProject(info) 
	with AkkaProject
	with Eclipsify
{
	val scalatest  = "org.scalatest" % "scalatest_2.9.0" % "1.4.1"
  
	val akka_repo = "Akka Maven Repository" at "http://akka.io/repository"
	
	val akka_teskit = akkaModule("testkit")
	
	// Protostuff, convinient API:s to serialize and deserialize protobuf
	//val protstuffRepo      = "Prostuff Repo" at "http://protostuff.googlecode.com/svn/repos/maven2"
	//val protostuffCore     = "com.dyuproject.protostuff" % "protostuff-core" % "1.0.0"
	//val protostuffCompiler = "com.dyuproject.protostuff" % "protostuff-compiler" % "1.0.0"
	
	// Active MQ implementation of protobuf (has lazy deserialization and memoized decoding/encoding)
	//val activemqProtobuf = "org.apache.activemq.protobuf" % "activemq-protobuf" % "1.1"

	// Concordion is a BDD test framework using HTML to specify tests.
    //val concordion = "org.concordion" % "concordion" % "1.4.1" % "test"
  
  override def testOptions = super.testOptions ++
    Seq(
        TestArgument(TestFrameworks.ScalaTest, "-oD")
        //,TestArgument(TestFrameworks.ScalaTest, "concordion.output.dir=target/concordion")
     )
     
   val jboss_repo = "JBoss Repository" at "https://repository.jboss.org/nexus/content/repositories/releases/"
   val netty = "org.jboss.netty" % "netty" % "3.2.4.Final"
}
