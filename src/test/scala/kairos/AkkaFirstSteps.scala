package kairos

import org.scalatest.WordSpec
import org.scalatest.matchers.ShouldMatchers
import akka.actor.Actor._
import akka.testkit.TestKit
import akka.util.duration._

class AkkaFirstSteps extends WordSpec with ShouldMatchers with TestKit {

  "A WriterActor" should {

    "persist events sent to it" in {

      val writer = actorOf[WriterActor].start

      within(15 millis) {
        writer ! SaveEvent(id = "MyId", data = "MyData")
        expectMsg("Done!")
        expectNoMsg
      }
    }
  }
}