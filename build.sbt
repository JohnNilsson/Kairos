name := "Kairos"

version := "0.0.1"

scalaVersion := "2.9.0-1"

libraryDependencies += "org.scalatest" % "scalatest_2.9.0" % "1.6.1" % "test"

libraryDependencies ++= {  
  val akkaVersion = "1.1.2"
  Seq(
    "se.scalablesolutions.akka" % "akka-actor"   % akkaVersion,
    "se.scalablesolutions.akka" % "akka-testkit" % akkaVersion
  )
}

libraryDependencies += "org.jboss.netty" % "netty" % "3.2.4.Final"

libraryDependencies += "org.msgpack" % "msgpack" % "0.5.2-devel"

resolvers += "Typesafe Repository" at "http://repo.typesafe.com/typesafe/releases"

resolvers += "JBoss Repository" at "https://repository.jboss.org/nexus/content/repositories/releases/"

resolvers += "MessagePack Repository" at "http://msgpack.org/maven2/"
