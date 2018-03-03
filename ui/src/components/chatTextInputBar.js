import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import AppBar from 'material-ui/AppBar';
import Toolbar from 'material-ui/Toolbar';
import Input, { InputAdornment } from 'material-ui/Input';
import IconButton from 'material-ui/IconButton';
import FaceIcon from 'material-ui-icons/Face';
import SendIcon from 'material-ui-icons/Send';

const styles = theme => ({
  chatTextInputBarToolBar: {
    backgroundColor: theme.palette.primary.contrastText,
    minHeight: '80px',
  },
});

class ChatTextInputBar extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.state = {
      message: "",
    }
    this.handleSendMessage = this.handleSendMessage.bind(this);
    this.handleInputChange = this.handleInputChange.bind(this);
  }

  handleSendMessage = function() {
    this.props.sendMessageCallback(this.state.message);
  }

  handleInputChange = function(event) {
    var value = event.target.value;
    this.setState({
      message: value
    })
  }
  
  render() {
    return (    
      <Grid item>
        <AppBar position="static" elevation={2}>
          <Toolbar className={ this.classes.chatTextInputBarToolBar }>            
            <Input 
              margin='dense'
              multiline
              fullWidth
              rows="3"
              value={ this.state.message }
              onChange={ this.handleInputChange }
              endAdornment={
                <InputAdornment position="end">
                  <IconButton color="primary" aria-label="Smiles">
                    <FaceIcon/>
                  </IconButton>
                  <IconButton 
                    color="primary" 
                    aria-label="Send"
                    onClick={ this.handleSendMessage }
                  >
                    <SendIcon/>
                  </IconButton>
                </InputAdornment>
              }
            />
          </Toolbar>
        </AppBar>
      </Grid>
    );
  }
}

ChatTextInputBar.propTypes = {
  classes: PropTypes.object.isRequired,
  sendMessageCallback: PropTypes.func,
};

ChatTextInputBar.defaultProps = {
  sendMessageCallback: ((newMessage) => {})
}

export default withStyles(styles)(ChatTextInputBar);
