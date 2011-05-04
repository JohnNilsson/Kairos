import sbt._

class Kairos(info: ProjectInfo) extends DefaultProject(info) {
  val scalatest  = "org.scalatest" % "scalatest" % "1.3"
  //val concordion = "org.concordion" % "concordion" % "1.4.1" % "test"
  
  override def testOptions = super.testOptions ++
    Seq(
        TestArgument(TestFrameworks.ScalaTest, "-oD")
        //,TestArgument(TestFrameworks.ScalaTest, "concordion.output.dir=target/concordion")
     )
}
