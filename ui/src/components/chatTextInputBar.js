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
  chatTextInputBar: {
  },
  chatTextInputBarToolBar: {
    backgroundColor: theme.palette.primary.contrastText,
    minHeight: '80px',
  },
  chatTextInputBarInput: {    
  }
});

class ChatTextInputBar extends React.Component {
  constructor(props) {
    super(props);
    this.state = {};
    this.classes = props.classes;
  }
  
  render() {
    return (    
      <Grid item className={ this.classes.chatTextInputBar }>
        <AppBar position="static" elevation={2}>
          <Toolbar className={ this.classes.chatTextInputBarToolBar }>            
            <Input margin='dense' multiline fullWidth rows="1" className={ this.classes.chatTextInputBarInput } endAdornment={
              <InputAdornment position="end">
                  <IconButton color="primary" aria-label="Smiles">
                    <FaceIcon/>
                  </IconButton>
                  <IconButton color="primary" aria-label="Send">
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
};

export default withStyles(styles)(ChatTextInputBar);
