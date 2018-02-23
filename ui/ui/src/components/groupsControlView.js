import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List, { ListItem, ListSubheader } from 'material-ui/List';
import TextField from 'material-ui/TextField';
import Button from 'material-ui/Button';
import RequestMessage from './requestMessage';

const styles = theme => ({
  sendRequestButton: {
    justifyContent: 'flex-end',
  },
  friendRequestCard: {
    backgroundColor: theme.palette.primary.main,
  }
});

class GroupsControlView extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() {    
    return (
      <Grid item>
        <List>
          {
            this.props.requests.map((request) => (
              <RequestMessage
                key={ request.uid }
                nickname={ request.nickname }
                time={ request.time }
              />
            ))
          }
          <ListSubheader disableSticky>
            Create group
          </ListSubheader>
          <ListItem>
            <TextField              
              defaultValue={ this.props.statusMessage }
              helperText="Group name"
              fullWidth
            />
          </ListItem>
          <ListItem className={ this.classes.sendRequestButton }>
            <Button color="secondary" >
              Create group
            </Button>
          </ListItem>
        </List>
      </Grid>
    );
  }
}

GroupsControlView.propTypes = {
  classes: PropTypes.object.isRequired,
  requests: PropTypes.array,
};

GroupsControlView.defaultProps = {
  requests: [],
} 

export default withStyles(styles)(GroupsControlView);
