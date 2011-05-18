
package kairos

import akka.actor.Actor
  
sealed trait KairosMessage
case class SaveEvent(id:EventId, data:EventData) extends KairosMessage

class WriterActor extends Actor {
  def receive = {
    case SaveEvent(id,data) => 
      self reply "Done!"
  }
}